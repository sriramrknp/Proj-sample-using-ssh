
// CS20B1107, CHEERLA SRIRAM REDDY


#include <iostream>
using namespace std;

// Base class, person
class person
{
    protected:
        string name;
        int roll_number;
    public:
        person(string Name, int rollNum)
        {
            name = Name;
            roll_number = rollNum;
        }
        void display()
        {
            cout << "Person" << endl;
            cout << "The name of person is: " << name << endl;
            cout << "The roll number of the student is: " << roll_number << endl;
            cout << endl;
        }
};

// Class student, inherits class person
class student : protected person
{
    protected:
        string cource1, cource2, cource3;
    public:
        student(string Name, int rollNum, string Cource1, string Cource2, string Cource3) : person(Name, rollNum)
        {
            cource1 = Cource1;
            cource2 = Cource2;
            cource3 = Cource3;            
        }
        void display()
        {
            cout << "student" << endl;
            person :: display();
            cout << "The cource 1 is: " << cource1 << endl;
            cout << "The cource 2 is: " << cource2 << endl;
            cout << "The cource 3 is: " << cource3 << endl;
            cout << endl;
        }
};

// Class research student, inherits class person
class researchStudent : protected person
{
    protected:
        string cource1;
        string research_area;
    public:
        researchStudent(string Name, int rollNum, string Cource1, string researchArea) : person(Name, rollNum)
        {
            cource1 = Cource1;
            research_area = researchArea;
        }
        void display()
        {
            cout << "research_area" << endl;
            person :: display();
            cout << "The cource 1 of research area is: " << research_area << endl;
            cout << "Research area: " << research_area << endl;
            cout << endl;
        }
};

// Class TA, inherits class student
class TA : protected student, protected researchStudent
{
    protected:
        string cource_assigned;
        string role;
    public:
        TA(string Name, int rollNum, string courceAssigned, string Role, string Cource1, string Cource2, 
                   string Cource3, string Cource_1, string research_area)
                      : student(Name, rollNum, Cource1, Cource2, Cource3),
                        researchStudent(Name, rollNum, Cource_1, research_area)
                        {
                            cource_assigned = courceAssigned;
                            role = Role;
                        }

        void display()
        {
            cout << "TA" << endl;
            student :: display();
            researchStudent :: display();
            cout << "The cource assigned to the TA: " << cource_assigned << endl;
            cout << "The role is: " << role << endl;
            cout << endl;
        }
};


// Main program
int main()
{
    string s[9] = {"NAME", "hello", "cse", "ece", "mech", "ai", "cse_ml", "role", "cource_assigned"};
    
    TA ta1(s[0], 78, s[7], s[8], s[2], s[3], s[4], s[5], s[6]);
    
    ta1.display();
    
    
    
    return 0;
}