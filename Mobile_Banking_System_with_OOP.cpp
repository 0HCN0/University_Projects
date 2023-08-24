// Group MSJ
// Project: Mobile Banking System with OOP
// Mohammad Mehedi Hasan.....ID: 2101002.
// Sifatul Islam Rafi........ID: 2101021.
// Md.Parvej Mosaraf.........ID: 2101024.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// main class
class user
{
private:
    char phoneNumber[12];
    int pin;
    int balance;

public:
    // Parameterized constructor
    user(int Balance, const char *PhoneNumber, int Pin)
    {
        balance = Balance;
        strncpy(phoneNumber, PhoneNumber, sizeof(phoneNumber));
        phoneNumber[sizeof(phoneNumber) - 1] = '\0';
        pin = Pin;
    }

    // Default constructor
    user()
    {
        balance = 0;
        phoneNumber[0] = '\0';
        pin = 0;
    }

    // phonenumber:
    void setPhonenumber(const char *pass)
    {
        strncpy(phoneNumber, pass, sizeof(phoneNumber));
        phoneNumber[sizeof(phoneNumber) - 1] = '\0';
    }
    const char *getPhonenumber()
    {
        return phoneNumber;
    }

    // pin:
    void setPin(int PIN)
    {
        pin = PIN;
    }
    int getPin()
    {
        return pin;
    }

    // balance:
    void setBalance(int Balance)
    {
        balance = Balance;
    }
    int getBalance()
    {
        return balance;
    }
    int leftBalance(int amount)
    {
        int leftBalance = balance - amount;
        return leftBalance;
    }
};

// A user-defined data type to show message.
struct message
{
    string toPhone;
    string fromPhone;
    int amount;
};

// Functions or methods:
// 1.Send Money:
void sendMoney(user *sender, user *receiver, int amount)
{
    if (sender->getBalance() >= amount)
    {
        sender->setBalance(sender->leftBalance(amount));
        receiver->setBalance(receiver->getBalance() + amount);
        cout << "Money sent successfully.\n";
    }
    else
    {
        cout << "Insufficient balance.\n";
    }
}

// 2.Cash Out:
void cashOut(user *user, int amount)
{
    if (user->getBalance() >= amount)
    {
        user->setBalance(user->leftBalance(amount));
        cout << "Cash out successful.\n";
    }
    else
    {
        cout << "Insufficient balance.\n";
    }
}

// 3.Mobile Recharge:
void mobileRecharge(user *user, int amount)
{
    user->setBalance(user->getBalance() - amount);
    cout << "Mobile recharge successful.\n";
}

// 4.Pay Bill:
void payBill(user *user, int amount)
{
    if (user->getBalance() >= amount)
    {
        user->setBalance(user->leftBalance(amount));
        cout << "Bill payment successful.\n";
    }
    else
    {
        cout << "Insufficient balance.\n";
    }
}

// Loop to choose option:
int WhatTodo()
{
    while (1)
    {
        int select;
        cin >> select;
        if (select == 1 || select == 2 || select == 3)
        {
            return select;
        }
        cout << "ERROR Enter again.\n";
    }
}

int main()
{
    // class object
    user defaultArr[5];
    int ptr = 2;

    // array to send message
    struct message Marr[10];
    int mptr = 0;

    {
        // default users
        defaultArr[0].setPhonenumber("01712345678");
        defaultArr[1].setPhonenumber("01312345678");

        defaultArr[0].setPin(1234);
        defaultArr[1].setPin(5678);

        defaultArr[0].setBalance(50000);
        defaultArr[1].setBalance(60000);
    }

    // Entry code
    string entryCode = "*1122#";
    string code;
    while (1)
    {
        // loop to verifi entry code
        cout << "Enter code (*1122#): ";
        getline(cin, code);

        if (code == entryCode)
        {
            break;
        }
        else
        {
            cout << "Code invalid.\n";
        }
    }
highjump:
    // Very first page
    cout << "\n1. Login.\n";
    cout << "2. Create Account.\n";
    cout << "3. Exit.\n";
    cout << "-> ";
    int whattodo = WhatTodo();
    if (whattodo == 3)
    {
        // End page
        cout << "\n********System Closed********" << endl;
        cout << endl;
        cout << "Group MSJ" << endl;
        cout << "Project: Mobile Banking System with OOP" << endl;
        cout << "Mohammad Mehedi Hasan.....ID: 2101002." << endl;
        cout << "Sifatul Islam Rafi........ID: 2101021." << endl;
        cout << "Md.Parvej Mosaraf.........ID: 2101024." << endl;
        cout << endl;

        return 0;
    }

    string phon;
    int PiN;
    int found = 0;
    int index;

    if (whattodo == 2)
    {
        // Creat Account
        cout << "\nEnter Phone number: ";
        cin >> phon;

        cout << "Set (4 digit) pin number: ";
        cin >> PiN;
        cin.ignore();
        defaultArr[ptr].setPhonenumber(phon.c_str());
        defaultArr[ptr].setPin(PiN);
        ptr++;

        // Logging in the newly created account
        index = ptr - 1;
        found = 1;
        cout << "Account created and logged in successfully.\n";
        goto highjump;
    }
    else
    {
    jump:
    {
        // Login
        cout << "\nEnter Phone Number: ";
        cin >> phon;

        for (int i = 0; i <= ptr; i++)
        {
            if (defaultArr[i].getPhonenumber() == phon)
            {
                index = i;
                found = 1;
            }
        }

        if (found != 1)
        {
            cout << "Wrong Phone Number.\n";
            goto jump;
        }
        else
        {
            // Verifing Pin
            cout << "Enter Pin: ";
            cin >> PiN;
            while (1)
            {
                if (defaultArr[index].getPin() == PiN)
                {
                    break;
                }
            }

            for (int i = 0; i <= mptr; i++)
            {
                if (Marr[i].toPhone == phon)
                {
                    cout << "You have received Tk " << Marr[i].amount << " from " << Marr[i].fromPhone << endl;
                    Marr[i].toPhone = '\0';
                    mptr--;
                }
            }

        smalljump:
            // Show options
            cout << "\nSelect an option:\n";
            cout << "1. My eKash(Main Menu)\n";
            cout << "2. Cash In (Deposit Money)\n";
            cout << "3. Back\n";
            cout << "-> ";
            int accountOption;
            cin >> accountOption;

            switch (accountOption)
            {
            case 1:
            {
                // 1.My eKash(Main Menu)
                break;
            }
            case 2:
            {
                // 2. Cash In (Deposit Money)
                int cashInAmount;
                cout << "\nEnter the amount to deposit: ";
                cin >> cashInAmount;
                defaultArr[index].setBalance(defaultArr[index].getBalance() + cashInAmount);
                cout << "Cash in successful." << endl;
                cout << "Cash in Tk " << cashInAmount << " From Agent store." << endl;
                break;
            }
            case 3:
            {
                // Very first page
                goto highjump;
            }
            default:
                cout << "Invalid option.\n";
            }
        }
    }
    }

    if (whattodo == 1)
    {
        while (1)
        {
            // Handling user operations after login
            while (1)
            {
                int operation;
                cout << "\nSelect an operation:\n";
                cout << "1. Send Money\n";
                cout << "2. Cash Out\n";
                cout << "3. Mobile Recharge\n";
                cout << "4. Pay Bill\n";
                cout << "5. Logout\n";
                cout << "6. Account Balance\n";
                cout << "7. Back\n";
                cout << "-> ";
                cin >> operation;

                switch (operation)
                {
                case 1:
                {
                    // Send Money
                    string receiverPhon;
                    int sendAmount;
                    cout << "\nEnter receiver's phone number: ";
                    cin >> receiverPhon;
                    cout << "Enter amount to send: ";
                    cin >> sendAmount;

                    // Find sender and receiver objects
                    user *receiver = nullptr;
                    for (int i = 0; i <= ptr; i++)
                    {
                        if (defaultArr[i].getPhonenumber() == receiverPhon)
                        {
                            receiver = &defaultArr[i];
                            break;
                        }
                    }

                    if (receiver != nullptr)
                    {
                        // 1.Send Money:
                        sendMoney(&defaultArr[index], receiver, sendAmount);
                        {
                            // For showing message.
                            Marr[mptr].toPhone = receiverPhon;
                            Marr[mptr].fromPhone = defaultArr[index].getPhonenumber();
                            Marr[mptr].amount = sendAmount;
                            mptr++;
                        }
                    }
                    else
                    {
                        cout << "Receiver not found.\n";
                    }

                    break;
                }
                case 2:
                {
                    // Cash Out
                    int cashOutAmount;
                    cout << "\nEnter cash out amount: ";
                    cin >> cashOutAmount;
                    cashOut(&defaultArr[index], cashOutAmount);
                    break;
                }
                case 3:
                {
                    // Mobile Recharge
                    int rechargeAmount;
                    cout<<"Enter Phone Number"<<endl;
                    string rphon;
                    cin>>rphon;
                    cout << "\nEnter recharge amount: ";
                    cin >> rechargeAmount;
                    mobileRecharge(&defaultArr[index], rechargeAmount);
                    break;
                }
                case 4:
                {
                    // Pay Bill
                    int billAmount;
                    cout << "\nEnter bill amount: ";
                    cin >> billAmount;
                    payBill(&defaultArr[index], billAmount);
                    break;
                }
                case 5:
                {
                    // Logout
                    cout << "\nLogged out.\n";
                    goto highjump;
                }
                case 6:
                {
                    // Balance
                    cout << "\nYour account balance: " << defaultArr[index].getBalance() << endl;
                    cout << endl;
                    break;
                }
                case 7:
                {
                    // Back
                    goto smalljump;
                }
                default:
                    cout << "Invalid operation.\n";
                }
            }
        }
    }

    return 0;
}
