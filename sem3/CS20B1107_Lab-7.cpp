// CS20B1107, CHEERLA SRIRAM REDDY
// Bank account problem

#include <iostream>
using namespace std;

// Class for node of linked list
class node
{
public:
    // To store the account number of user
    int accounNum;
    // To store ubdated bank balance
    double accountBlc;
    // Next pointer
    node *next;
};

// Base class Account

class account
{
private:
    double accBal;
    int accNum;

public:
    // Parameterized constructor of account class(base class)
    account(double accbal)
    {

        if (accbal >= 0.0)
        {
            accBal = accbal;
        }
        else
        {
            accBal = 0.0;
            cout << "The initial balance was invalid" << endl;
        }
    }

    // Ubdates account balance
    double Accblc(double AccBlc)
    {
        accBal = AccBlc;
        return accBal;
    }

    // Takes account number as user input
    int accnum(int accnum)
    {
        accNum = accnum;
        return accNum;
    }

    // Used to credit amount in respective bank account
    double credit(double camt)
    {
        if (camt >= 0.0)
            accBal = accBal + camt;
        else
            cout << "Entered amount is invalid, please, try again!" << endl;
        return accBal;
    }

    // Used to debit amount in respective bank account
    double debit(double damt)
    {
        if (accBal > 0)
        {
            if (damt > accBal)
            {
                cout << "Debit amount exdeed the account balance" << endl;
            }
            else
            {
                accBal = accBal - damt;
            }
        }
        else
            cout << "The account balance is insufficient to debit money" << endl;
        return accBal;
    }

    // To get account balance
    double getBal()
    {
        return accBal;
    }
};

/* Derived class savings account inherits base class Account */

class savingsAccount : public account
{
private:
    double intrate_percentage;
    double accbals;

public:
    // Parameterized constructor, of derives class, invokes base class constructor
    savingsAccount(double accbalsa, double intrate_Percentage) : account(accbalsa)
    {
        accbals = accbalsa;
        intrate_percentage = intrate_Percentage;
    }

    // Ubdates account balance of particular bank account
    double accblc(double accblc_sa)
    {
        accbals = accblc_sa;
        return accbals;
    }

    // Takes the intrest rate from the user
    double intrestRate(double intrest_rate)
    {
        intrate_percentage = intrest_rate;
        return intrate_percentage;
    }

    // Caluclates intrest for avalable balance and ubdates the account balance
    double caluclateintrest()
    {
        double intrest_earned;
        intrest_earned = accbals * intrate_percentage;
        return intrest_earned;
    }
};

/* Derived class chekingsaccount inherits the base class account */

class checkingAccount : public account
{
private:
    double feePer_Transaction;
    double accBlcC;

public:
    // Parameterized constructor, of derives class, invokes base class constructor
    checkingAccount(double accblcc, double feeper_transaction) : account(accblcc)
    {
        accBlcC = accblcc;
        feePer_Transaction = feeper_transaction;
    }

    // ubdates the account balance
    double accblc(double accblc_ca)
    {
        accBlcC = accblc_ca;
        return accBlcC;
    }

    // Tkaing from user that, charge fee for successfull transaction
    double feeTransaction(double feePerTransac)
    {
        feePer_Transaction = feePerTransac;
        return feePer_Transaction;
    }

    // Charging fee, for a successfull transaction
    double creditc(double camt)
    {
        if (camt >= feePer_Transaction)
            accBlcC = camt - feePer_Transaction;
        else
            cout << "Transaction couldn't complete, because of insufficiant balance: " << endl;
        return accBlcC;
    }

    // Charging fee, for a successfull transaction
    double debitc(double damtca)
    {
        if (damtca >= feePer_Transaction)
            accBlcC = damtca - feePer_Transaction;
        else
            cout << "The transaction couln't complete because of insufficient balance: " << endl;
        return accBlcC;
    }
};

// Main program
int main()
{
    double intrest_rate, accblc_sa, accblc_ca, feeper_trsc;
    double crdt, dbt;
    double dbtca;
    double retCredit, retDebit;
    int accnum, choice;
    int j = 1, k = 1;

    // Two separate head pointers for svings account and checkings account
    node *headSA = NULL;
    node *headCA = NULL;
    node *nodeSA = new node();
    node *nodeCA = new node();

    // Object creation for two derived classes
    savingsAccount sa1(accblc_sa, accnum);
    checkingAccount ca1(accblc_ca, feeper_trsc);

    // Menu
    while (1)
    {
        cout << "   1. Open account in savings or checkings account." << endl;
        cout << "   2. Credit amount in Savings or Checking Account)." << endl;
        cout << "   3. Debit amount in Savings or Checking Account." << endl;
        cout << "   4. Change/Update Interest rate in Savings Account." << endl;
        cout << "   5. Calculate Interest for Savings Account - (Print)." << endl;
        cout << "   6. Calculate and Update Interest for Savings Account - (Credit)." << endl;
        cout << "   7. Change/Update Fee Amount for Checking Account" << endl;
        cout << "   8. Print Checking Fee for Checking Account." << endl;
        cout << "   9. Transact and Update for Checking Account - (Debit)." << endl;
        cout << "   10. Exit." << endl;
        cout << "   11. print the account details: " << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
 
        case 1:
            cout << "choose 1. for savings " << endl;
            cout << "       2. for checking" << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the account number for savings account:" << endl;
                cin >> accnum;
                sa1.accnum(accnum);
                cout << "Enter the initial balance for savings account:" << endl;
                cin >> accblc_sa;

                // Storing the details of user in a separate linked list of savings
                if (headSA == NULL)
                {
                    nodeSA->accounNum = accnum;
                    nodeSA->accountBlc = accblc_sa;
                    nodeSA->next = NULL;
                }
                else
                {
                    node *ptrSA = new node();
                    ptrSA->accounNum = accnum;
                    ptrSA->accountBlc = accblc_sa;
                    ptrSA->next = NULL;
                    nodeSA->next = ptrSA;
                    nodeSA = ptrSA;
                }

                sa1.accblc(accblc_sa);
                sa1.Accblc(accblc_sa);
                cout << "Enter the intrest rate for savings account:" << endl;
                cin >> intrest_rate;
                sa1.intrestRate(intrest_rate);
                if (headSA == NULL)
                {
                    headSA = nodeSA;
                }
            }
            else
            {
                cout << "Enter the account number for checkings account:" << endl;
                cin >> accnum;
                ca1.accnum(accnum);
                cout << "Enter the initial balance for checkings account:" << endl;
                cin >> accblc_ca;

                // Storing the details of user in a separate linked list of savings
                if (headCA == NULL)
                {
                    nodeCA->accounNum = accnum;
                    nodeCA->accountBlc = accblc_ca;
                    nodeCA->next = NULL;
                }
                else
                {
                    node *ptrCA = new node();
                    ptrCA->accounNum = accnum;
                    ptrCA->accountBlc = accblc_ca;
                    ptrCA->next = NULL;
                    nodeCA->next = ptrCA;
                    nodeCA = ptrCA;
                }

                ca1.accblc(accblc_ca);
                ca1.Accblc(accblc_ca);
                cout << "Enter the fee per transaction for checkings account:" << endl;
                cin >> feeper_trsc;
                ca1.feeTransaction(feeper_trsc);

                if (headCA == NULL)
                {
                    headCA = nodeCA;
                }
            }
            break;

        case 2:
            cout << "choose 1. for savings " << endl;
            cout << "       2. for checking" << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter ammount to credit in account number " << sa1.accnum(accnum) << " for savings account: " << endl;
                cin >> crdt;

                nodeSA->accountBlc = sa1.credit(crdt);

                cout << "Ubdated balance in account num " << sa1.accnum(accnum) << " is: " << nodeSA->accountBlc << endl;
            }
            else
            {
                cout << "Enter the amount to credit in account num " << ca1.accnum(accnum) << " for checkings account:" << endl;
                cin >> crdt;
                retCredit = ca1.credit(crdt);
                nodeCA->accountBlc = ca1.creditc(retCredit);

                cout << "Ubdated balance in account num " << ca1.accnum(accnum) << " is: " << nodeCA->accountBlc << endl;
                ca1.Accblc(ca1.creditc(retCredit));
            }
            break;

        case 3:
            cout << "choose 1. for savings " << endl;
            cout << "       2. for checking" << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter ammount to debit in account number " << sa1.accnum(accnum) << " for savings account: " << endl;
                cin >> dbt;

                nodeSA->accountBlc = sa1.debit(dbt);

                cout << "Ubdated balance in account num: " << sa1.accnum(accnum) << " is: " << nodeSA->accountBlc << endl;
            }
            else
            {
                cout << "Enter the amount to debit in account num " << ca1.accnum(accnum) << " for checkings account:" << endl;
                cin >> dbtca;
                retDebit = ca1.debit(dbtca);
                nodeCA->accountBlc = ca1.debitc(retDebit);

                cout << "Ubdated balance in account num: " << ca1.accnum(accnum) << " is: " << nodeCA->accountBlc << endl;
                ca1.Accblc(ca1.debitc(retDebit));
            }
            break;

        case 4:
            cout << "Enter the new intrest rate for the savings account: " << endl;
            cin >> intrest_rate;
            cout << "The intrest rate for savings account is: " << sa1.intrestRate(intrest_rate) << endl;
            break;

        case 5:
            cout << "Caluclated intrest of savings account: " << sa1.caluclateintrest() << endl;
            break;

        case 6:
            nodeSA->accountBlc = sa1.Accblc(sa1.credit(sa1.caluclateintrest()));
            cout << "Ubdated account balance: " << nodeSA->accountBlc << endl;
            break;

        case 7:
            cout << "Enter the new charge of fee per transaction: " << endl;
            cin >> feeper_trsc;
            cout << "The fee per transaction is for checkings account is: " << ca1.feeTransaction(feeper_trsc) << endl;
            break;

        case 8:
            cout << "The fee per transaction for checkings account is: " << feeper_trsc << endl;
            break;

        case 9:
            cout << "Enter the amount to debit in account num for checkings account:" << ca1.accnum(accnum) << endl;
            cin >> dbtca;
            retDebit = ca1.debit(dbtca);
            nodeCA->accountBlc = ca1.debitc(retDebit);

            cout << "Ubdated balance in account num: " << ca1.accnum(accnum) << " is: " << nodeCA->accountBlc << endl;
            ca1.Accblc(ca1.debitc(retDebit));
            break;

        case 10:
            exit(0);
            break;
        case 11:
            node *ptrS = headSA;
            node *ptrC = headCA;

            // Display of account details
            cout << "Enter 1 to display savings acc else 2: " << endl;
            cin >> choice;
            if (choice == 1)
            {
                k = 1;
                while (ptrS != NULL)
                {
                    cout << "   Account - " << k << endl;
                    cout << "Account number: " << ptrS->accounNum << endl;
                    cout << "Account balance: " << ptrS->accountBlc << endl;
                    ptrS = ptrS->next;
                    k++;
                }
            }
            else
            {
                j = 1;
                while (ptrC != NULL)
                {
                    cout << "   Account - " << j << endl;
                    cout << "Account number: " << ptrC->accounNum << endl;
                    cout << "Account balance: " << ptrC->accountBlc << endl;
                    ptrC = ptrC->next;
                    j++;
                }
            }
        }
    }

    return 0;
}
