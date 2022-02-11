// CS20B1107, CHEERLA SRIRAM REDDY
// Program to caluclate area of traingle, rectangle and square
// by inheritance


#include <iostream>
using namespace std;

// Base class
class twoDShape
{
    protected:
        int xdim,ydim;
    public:
        // Sets the Dimentions
        void setDimentions(int xDim, int yDim)
        {
            xdim = xDim;
            ydim = yDim;
        }
        void getDimentions()
        {
            cout << " " << xdim << " " << ydim <<endl;
        }
};

// One of the derived class, inherits the class twoDShape
class triangle : protected twoDShape
{
    protected:
    
    // clculates area
    double calculateArea()
    {
        return (0.5)*xdim*ydim;
    }
    public:
       // since protected, we cannot access directly through object
       void set_dimentions(int x_dim, int y_dim)
       {
           // In base class
           setDimentions(x_dim, y_dim);
       }
       void get_dimentions()
       {
           cout << "The base and height lengths of a traingle:";
           // In base class
           getDimentions();
       }
       int calculate_area()
       {
           // In base classs
           int x = calculateArea();
           return x;
       }
};


// One of the derived class, inherits the class twoDShape
class rectangle : protected twoDShape
{
    protected:
    int calculateArea()
    {
        return xdim*ydim;
    }
    public:
       void set_dimentions(int x_dim, int y_dim)
       {
           // In base class
           setDimentions(x_dim, y_dim);
       }
       void get_dimentions()
       {
           cout << "The length and breadth lengths of a rectangle:";
           // In base class
           getDimentions();
       }
       int calculate_area()
       {
           // In base class
           return calculateArea();
       }
};


// One of the derived class, inherits the class twoDShape
class square : protected twoDShape
{
    protected:
    // calculates area
    int calculateArea()
    {
        if( xdim == ydim)
            return xdim*xdim;
        else
            cout << "The entered Dimentions are not valid for the square" <<  endl;
        
        return 0;
    }
    public:
       void set_dimentions(int x_dim, int y_dim)
       {
           // In base class
           setDimentions(x_dim, y_dim);
       }
       void get_dimentions()
       {
           cout << "The side length of a square:";
           // In base class
           getDimentions();
       }
       int calculate_area()
       {
           // In base class
           return calculateArea();
       }
};


// Main Program
int main()
{
    int choice = 1;
    int x_dim, y_dim;

    // Object creation
    triangle tr1;
    rectangle rec1;
    square sq1;
    
    while(1)
    {
        cout << "  choose 1. to 'Set Dimentions' " << endl;
        cout << "  choose 2. to 'Get Dimentions' " << endl;
        cout << "  choose 3. to 'Calcualte Area of the Triangle' " << endl;
        cout << "  choose 4. to 'Calculate Area of the Rectangle' " << endl;
        cout << "  choose 5. to 'Calculate Area of the Square' " << endl;
        cout << "  choose 6. to 'Exit' " << endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter the dimentions xdim: " << endl;
                cin >> x_dim;
                cout << "Enter the dimentions ydim: " << endl;
                cin >> y_dim;
                if( x_dim >= 0 && y_dim >= 0)
                {
                    tr1.set_dimentions(x_dim, y_dim);
                    if(x_dim > y_dim)
                        rec1.set_dimentions(x_dim, y_dim);
                    else 
                        rec1.set_dimentions(y_dim, x_dim);
                    sq1.set_dimentions(x_dim, y_dim);
                }
                else 
                {
                    cout << "The entered dimentions are 'invalid' or '< 0'" << endl;
                }
                break;
            case 2:
                tr1.get_dimentions();
                rec1.get_dimentions();
                sq1.get_dimentions();
                break;
            case 3:
                cout << "The Triangle area is: "<< tr1.calculate_area() << endl;
                break;
            case 4:
                cout << "The Rectangle area is: " << rec1.calculate_area() << endl;
                break;
            case 5:
                if( x_dim == y_dim)
                    cout << "The square area is: " << sq1.calculate_area() << endl;
                else 
                    cout << "The entered dimentions is not valid for square or(x_dim != y_dim) " << endl;
                break;
            case 6:
                exit(0);
                
        }
    }
    return 0;
}