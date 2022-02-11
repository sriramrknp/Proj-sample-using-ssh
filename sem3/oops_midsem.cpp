#include <iostream>
using namespace std;

class twoDShape
{
    protected:
        int xdim,ydim;
    public:
        void setDimentions(int xDim, int yDim)
        {
            xdim = xDim;
            ydim = yDim;
        }
        void getDimentions()
        {
            cout << "The dimentions are: xdim = " << xdim << " ydim =  " << ydim <<endl;
        }
};

class triangle : protected twoDShape
{
    double calculateArea()
    {
        return (1/2)*xdim*ydim;
    }
};

class rectangle : protected twoDShape
{
    int calculateArea()
    {
        return xdim*ydim;
    }
};

class square : protected twoDShape
{
    int calculateArea()
    {
        if( xdim == ydim)
            return xdim*ydim;
        else
            cout << "The entered Dimentions are not valid for the square" <<  endl;
    }
};


int main()
{
    int choice = 1, x_dim, y_dim;
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
                cout << "Enter the dimentions xdim and ydim: " << endl;
                cin >> x_dim >> y_dim;
                if( x_dim >= 0 && y_dim >= 0)
                {
                    tr1.setDimentions(x_dim, y_dim);
                    rec1.setDimentions(x_dim, y_dim);
                    sq1.setDimentions(x_dim, y_dim);
                }
                else 
                {
                    cout << "The entered dimentions are 'invalid' or '< 0'" << endl;
                }
            case 2:
                tr1.getDimentions();
                rec1.getDimentions();
                if( x_dim == y_dim)
                    sq1.getDimentions();
                else
                    cout << "The given dimentions not valid for square " << endl;
            case 3:
                tr1.calculateArea();
            case 4:
                rec1.calculateArea();
            case 5:
                sq1.calculateArea();
            case 6:
                exit(0);
        }
    }
    return 0;
}