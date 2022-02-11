// CS20B1107, CHEERLA SRIRAM REDDY

// Calculator program using class template

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Template class
template <typename T>
class calculator
{
public:
    T val1;
    T val2;
    T resultA, resultS, resultM, resultD, resultEX;

    void setInput(T _val1, T _val2)
    {
        val1 = _val1;
        val2 = _val2;
    }
    void addition()
    {
        // Addition of two numbers
        // two numbers can be negative of or positive
        resultA = val1 + val2;
    }
    void substraction()
    {
        // substraction of two numbers
        // two numbers can be negative of or positive
        resultS = val1 - val2;
    }
    void multiplication()
    {
        // Multiplication of two numbers
        // two numbers can be negative of or positive
        resultM = val1 * val2;
    }
    void division()
    {
        // Division of two numbers
        // two numbers can be negative of or positive
        try
        {
            if(val2 != 0)
                resultD = val1 / val2;
            else
                throw 1;
        }
        catch(...)
        {
            cout << "The value 2 is 0, invalid!" << endl;
        }
    }
    void exponent(int option)
    {
        // Exponent for val1 is val2
        //  since any value can be negative
        //  i have used val2 as exponent for val1

        if(option == 2)
            // if values are floating point numbers
            resultEX = pow(val1, val2);
        else 
        {
            // If values are integers
            resultEX = 1;
            for (int i = 0; i < val2; i++)
            {
                resultEX = resultEX * val1;
            }
        }
    }

    void display(int option)
    {
        // Displays sum
        if(option == 1)
        {
            cout << "The two varaibles are: " << val1 << " " << val2 << endl;
            cout << "The Sum of two selected varaibles is: " << resultA << endl;
        }
        // Displays substraction
        if (option == 2)
        {
            cout << "The two varaibles are: " << val1 << " " << val2 << endl;
            cout << "The Substraction of two selected varaibles is: " << resultS << endl;
        }
        // Displays multiplication
        if (option == 3)
        {
            cout << "The two varaibles are: " << val1 << " " << val2 << endl;
            cout << "The Multiplication of two selected varaibles is: " << resultM << endl;
        }
        // Displays division
        if (option == 4)
        {
            cout << "The two varaibles are: " << val1 << " " << val2 << endl;
            cout << "The Division of two selected varaibles is: " << resultD << endl;
        }
        // Displays exponent of val1 to val2
        if (option == 5)
        {
            cout << "The two varaibles are: " << val1 << " " << val2 << endl;
            cout << "The Exponent of two selected varaibles(val1^val2) is: " << resultEX << endl;
        }
        
    }
};

int main()
{
    int choice, choiceD;
    int val1_I, val2_I;
    float val1_F, val2_F;
    string val1_S, val2_S;

    // Object of integers
    calculator<int> integers;

    // Object of floating point numbers
    calculator<float> floating;

    // Obkect of strings
    calculator<string> strings;

    while (1)
    {
        cout << "\033[1;31m";
        cout << "  Choose   1. to 'Set input'. " << endl;
        cout << "  Choose   2. to 'Addition'. " << endl;
        cout << "  Choose   3. to 'Substraction'. " << endl;
        cout << "  Choose   4. to 'Multiplication'. " << endl;
        cout << "  Choose   5. to 'Divison'. " << endl;
        cout << "  Choose   6. to 'Exponent'. " << endl;
        cout << "  Choose   7. to 'Display'. " << endl;
        cout << "  Choose   8. Exit." << endl;

        cout << "Enter your choice: \033[0m" << endl;
        cin >> choice;

        switch (choice)
        {

        // Sets input
        case 1:
            cout << "choose 1. to Integers" << endl;
            cout << "       2. to Floating Numbers" << endl;
            cout << "       3. to String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter the two integers: " << endl;
                cin >> val1_I >> val2_I;
                integers.setInput(val1_I, val2_I);
            }
            if (choice == 2)
            {
                cout << "Enter the two floating numbers: " << endl;
                cin >> val1_F >> val2_F;
                floating.setInput(val1_F, val2_F);
            }
            if (choice == 3)
            {
                cout << "Enter the two strings: " << endl;
                cin >> val1_S >> val2_S;
                strings.setInput(val1_S, val2_S);
            }
            break;

        // Addition
        case 2:
            cout << "choose 1. to Add Integers" << endl;
            cout << "       2. to Add Floating Numbers" << endl;
            cout << "       3. to Add String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                integers.addition();
            }
            if (choice == 2)
            {
                floating.addition();
            }
            if (choice == 3)
            {
                strings.addition();
            }
            break;

        // Substraction
        case 3:
            cout << "choose 1. to Subtract Integers" << endl;
            cout << "       2. to Subtract Floating Numbers" << endl;
            cout << "       3. to Subtract String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                integers.substraction();
            }
            if (choice == 2)
            {
                floating.substraction();
            }
            if (choice == 3)
            {
                // Substraction can't be handled
                // so error handled by try catch
                try
                {
                    throw(1);
                }
                catch(...)
                {
                    cout << "Can't substract strings" << endl;
                }
            }
            break;

        // Multiplication
        case 4:
            cout << "choose 1. to Multiply Integers" << endl;
            cout << "       2. to Multiply Floating Numbers" << endl;
            cout << "       3. to Multiply String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                integers.multiplication();
            }
            if (choice == 2)
            {
                floating.multiplication();
            }
            if (choice == 3)
            {
                // Multiplication can't be handled
                // so error handled by try catch
                try
                {
                    throw(1);
                }
                catch (...)
                {
                    cout << "Can't Multiply srtings" << endl;
                }
            }
            break;

        // Division
        case 5:
            cout << "choose 1. to Divide Integers" << endl;
            cout << "       2. to Divide Floating Numbers" << endl;
            cout << "       3. to Divide String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                integers.division();
            }
            if (choice == 2)
            {
                floating.division();
            }
            if (choice == 3)
            {
                // division can't be handled
                // so error handled by try catch
                try
                {
                    throw(1);
                }
                catch (...)
                {
                    cout << "Can't Divide strings" << endl;
                }
            }
            break;

        // Exponent
        case 6:
            cout << "choose 1. to Exponent Integers" << endl;
            cout << "       2. to Exponent add Floating Numbers" << endl;
            cout << "       3. to Exponent add String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                choiceD = choice;
                integers.exponent(choice);
            }
            if (choice == 2)
            {
                choiceD = choice;
                floating.exponent(choice);
            }
            if (choice == 3)
            {
                // Exponent can't be handled 
                // so error handled by try catch
                try
                {
                    throw(1);
                }
                catch (...)
                {
                    cout << "Can't Exponent strings" << endl;
                }
            }
            break;

        // Display
        case 7:
            cout << "choose 1. to Display Integers" << endl;
            cout << "       2. to Display Floating Numbers" << endl;
            cout << "       3. to Display String" << endl;
            cin >> choice;

            if (choice == 1)
            {
                cout << "choose 1. to Display Addition" << endl;
                cout << "       2. to Display Substraction" << endl;
                cout << "       3. to Display Multiplication" << endl;
                cout << "       4. to Display Dividion" << endl;
                cout << "       5. to Display Exponent" << endl;
                cin >> choiceD;
                integers.display(choiceD);
            }
            if (choice == 2)
            {
                cout << "choose 1. to Display Addition" << endl;
                cout << "       2. to Display Substraction" << endl;
                cout << "       3. to Display Multiplication" << endl;
                cout << "       4. to Display Dividion" << endl;
                cout << "       5. to Display Exponent" << endl;
                cin >> choiceD;
                floating.display(choiceD);
            }
            if (choice == 3)
            {
                cout << "choose 1. to Display Addition" << endl;
                cout << "       2. to Display Substraction" << endl;
                cout << "       3. to Display Multiplication" << endl;
                cout << "       4. to Display Dividion" << endl;
                cout << "       5. to Display Exponent" << endl;
                cin >> choiceD;

                if(choiceD == 1)
                {
                    // since only addition happens
                    // So only displays addition
                    strings.display(choiceD);
                }
                else 
                {
                    // Else all cases error handled by 
                    // try catch
                    try
                    {
                        throw(1);
                    }
                    catch (...)
                    {
                        cout << "Can't display strings" << endl;
                    }
                }
            }
            break;
        

        case 8:
            exit(0);
        }
    }
    return 0;
}