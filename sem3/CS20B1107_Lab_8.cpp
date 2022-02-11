// CS20B1107, CHEERLA SRIRAM REDDY.
// Lab - 8, manager and intern problem.

#include <iostream>
#include <string>
using namespace std;

// Node - 1 class, stores the manager employee details
class node1
{
    public:
        int employee_id;
        string employee_name;
        float monthly_pay;
        node1 *next;
};

// Node - 2 class, stores the intern employee details
class node2
{
    public:
        int employee_id;
        string employee_name;
        float hourly_pay;
        node2 *next;
};

// base class employee
class employee
{
    protected:
        int employee_ID;
        string employee_name;
};

// Class contarct, inherits the class employee
class contract : protected employee
{
    protected:
        float pay_per_hour;
    public:
        // Sets the details
        void setPay(int employeeID, string employeename, float payperHour)
        {
            employee_ID = employeeID;
            employee_name = employeename;
            pay_per_hour = payperHour;
        }
        
        // Prints the details
        void getPay()
        {
            cout << "The employee_ID is: " << employee_ID << endl;
            cout << "The employee_name is: " << employee_name << endl;
            cout << "The pay_per_hour of employee is: " << pay_per_hour << endl;
        }
};

// Class salaried, inherits the class employee
class salaried : protected employee
{
    protected:
        float monthly_Pay;
    public:
        // Sets the details
        void setPay(int employeeID, string employeename, float monthlypay)
        {
            employee_ID = employeeID;
            employee_name = employeename;
            monthly_Pay = monthlypay;
        }
        
        // Gets the details
        void getPay()
        {
            cout << "The employee_ID is: " << employee_ID << endl;
            cout << "The employee_name is: " << employee_name << endl;
            cout << "The pay_per_hour of employee is: " << monthly_Pay << endl;
        }
};

// Class manager, inherits the class salaried
class manager : private salaried
{
    public:
        // ubdates employee_ID, employee_name and monthlyPay
        void setDetails(int employeID, string employeename, float monthlypay)
        {
            setPay(employeID, employeename, monthlypay);
        }
        
        // getDetails prints the values stored in these member functions
        void getDetails()
        {
            getPay();
        }
        
        // caculateSalary gets the number of working months and prints 
        // the total salary for the number of months the manager has worked
        float calculateSalary(float monthsWorked)
        {
            return (monthly_Pay*monthsWorked);
        }
        
        // setSalary updates the salary of the manager
        void setSalary(float monthlypay)
        {
            monthly_Pay = monthlypay;
        }
};

// Class intern classes, inherits the class contract
class internClasses : private contract
{
    public:
        // ubdates employee_ID, employee_name and hourlyPay
        void setDetails(int employeeID, string employeename, float payperHour)
        {
            setPay(employeeID, employeename, payperHour);
        }
        
        // getDetails prints the values stored in these member functions
        void getDetails()
        {
            getPay();
        }
        
        // setSalary updates the salary of the intern
        void setSalary(float hourlyPay)
        {
            pay_per_hour = hourlyPay;
        }
        
        // caculateSalary gets the number of working hours and prints 
        // the total salary for the number of hours the intern has worked
        float calculateSalary(float hoursWorked)
        {
            return (pay_per_hour*hoursWorked);
        }
};

// Main program
int main()
{
    int employeeID;
    string employeeName;
    float payPerHour;
    float monthlyPay;
    float monthswrk, hourswrk;
    
    int choice;
    string toChoose;
    
    // Object creation
    manager m1;
    internClasses ic1;
    
    // Linked list creation, head and first node
    // of two manager and intern
    node1 *headM = NULL;
    node2 *headI = NULL;
    node1 *nodeM = new node1();
    node2 *nodeI = new node2();
    
    
    while(1)
    {
        // Menu
        cout << endl;
        cout << "   Choose 1 to 'Create Employee (Manager or Intern)' " << endl;
        cout << "   Choose 2 to 'Update Employee Details (Manager or Intern)' " << endl;
        cout << "   Choose 3 to 'Print Employee Details (Manager or Intern)' " << endl;
        cout << "   Choose 4 to 'Update Pay (Manager or Intern)' " << endl;
        cout << "   Choose 5 to 'Calculate Salary (Manager or Intern)' " << endl;
        cout << "   Choose 6 to 'Exit' " << endl;
        cin >> choice;
        cout << endl;
        
        switch(choice)
        {
            case 1:
                cout << "Choose 1 to 'Manager' " << endl;
                cout << "       2 to 'Intern' " << endl;
                cin >> choice;
                if(choice == 1)
                {
                    cout << "Enter the Manager_Id: " << endl;
                    cin >> employeeID;
                    cout << "Enter the Manager name: " << endl;
                    getline(cin >> ws, employeeName);
                    cout << "Enter the monthly_Pay amount: "<< endl;
                    cin >> monthlyPay;
                    
                    // Storing the data in linked list
                    if(headM == NULL)
                    {
                        nodeM->employee_id = employeeID;
                        nodeM->employee_name = employeeName;
                        nodeM->monthly_pay = monthlyPay;
                        headM = nodeM;
                    }
                    else 
                    {
                        node1 *ptrM = new node1();
                        ptrM->employee_id = employeeID;
                        ptrM->employee_name = employeeName;
                        ptrM->monthly_pay = monthlyPay;
                        ptrM->next = NULL;
                        nodeM->next = ptrM;
                        nodeM = ptrM;
                    }
                    m1.setDetails(employeeID, employeeName, monthlyPay);
                }
                else
                {
                    cout << "Enter the Intern_Id: " << endl;
                    cin >> employeeID;
                    cout << "Enter the Intern name: " << endl;
                    getline(cin >> ws, employeeName);
                    cout << "Enter the hourly_Pay amount: "<< endl;
                    cin >> payPerHour;
                    
                    // Storing the Details in linked list
                    if(headI == NULL)
                    {
                        nodeI->employee_id = employeeID;
                        nodeI->employee_name = employeeName;
                        nodeI->hourly_pay = payPerHour;
                        headI = nodeI;
                    }
                    else 
                    {
                        node2 *ptrI = new node2();
                        ptrI->employee_id = employeeID;
                        ptrI->employee_name = employeeName;
                        ptrI->hourly_pay = payPerHour;
                        ptrI->next = NULL;
                        nodeI->next = ptrI;
                        nodeI = ptrI;
                    }
                    ic1.setDetails(employeeID, employeeName, payPerHour);
                }
                break;


            case 2:
                cout << "Choose 1 to 'Manager' " << endl;
                cout << "       2 to 'Intern' " << endl;
                cin >> choice;
                if(choice == 1)
                {
                    cout << "Do you want to change the employeeID put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the Manager_Id: " << endl;
                        cin >> employeeID;
                        nodeM->employee_id = employeeID;
                    }
                    
                    cout << "Do you want to change the employeeName put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the Manager name: " << endl;
                        getline(cin >> ws, employeeName);
                        nodeM->employee_name = employeeName;
                    }
                    
                    cout << "Do you want to change the monthlyPay put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the monthly_Pay amount: "<< endl;
                        cin >> monthlyPay;
                        nodeM->monthly_pay = monthlyPay;
                    }
                    m1.setDetails(employeeID, employeeName, monthlyPay);
                }
                else
                {
                    cout << "Do you want to change the employeeID put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the Intern_Id: " << endl;
                        cin >> employeeID;
                        nodeI->employee_id = employeeID;
                    }
                    
                    cout << "Do you want to change the employeeName put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the Intern name: " << endl;
                        getline(cin >> ws, employeeName);
                        nodeI->employee_name = employeeName;
                    }
                    
                    cout << "Do you want to change the hourlyPay put yes/no: " <<endl;
                    cin >> toChoose;
                    if(toChoose == "yes")
                    {
                        cout << "Enter the hourly_Pay amount: "<< endl;
                        cin >> payPerHour;
                        nodeI->hourly_pay = payPerHour;
                    }
                    ic1.setDetails(employeeID, employeeName, payPerHour);
                }
                break;


            case 3:
                cout << "Choose 1 to 'Manager' " << endl;
                cout << "       2 to 'Intern' " << endl;
                cin >> choice;
                if(choice == 1)
                {
                    // Prints the details of manager
                    m1.getDetails();
                }
                else
                {
                    // Prints the details of the intern 
                    ic1.getDetails();
                }
                break;


            case 4:
                cout << "Choose 1 to 'Manager' " << endl;
                cout << "       2 to 'Intern' " << endl;
                cin >> choice;
                if(choice == 1)
                {
                    // Manager
                    cout << "Enter the new monthlyPay: " << endl;
                    cin >> monthlyPay;
                    m1.setSalary(monthlyPay);
                    nodeM->monthly_pay = monthlyPay;
                }
                else
                {
                    // Intern 
                    cout << "Enter the new payPerHour: " << endl;
                    cin >> payPerHour;
                    nodeI->hourly_pay = payPerHour;
                    ic1.setSalary(payPerHour);
                }
                break;


            case 5:
                cout << "Choose 1 to 'Manager' " << endl;
                cout << "       2 to 'Intern' " << endl;
                cin >> choice;
                if(choice == 1)
                {
                    // Taking input of months worked
                    cout << "Enter the number of months worked: " << endl;
                    cin >> monthswrk;
                    cout << "The calculated salary for " << monthswrk;
                    cout << " months worked: " << m1.calculateSalary(monthswrk) << endl;
                }
                else
                {
                    // Taking input of hours worked
                    cout << "Enter the number of hours worked: " << endl;
                    cin >> hourswrk;
                    cout << "The calculated salary for " << hourswrk;
                    cout << " hours worked: " << ic1.calculateSalary(hourswrk) << endl;
                }
                break;


            case 6:
                exit(0);
                break;
            
        }
    }
    return 0;
}