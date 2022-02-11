// CS20B1107, CHEERLA SRIRAM REDDY
/* Program to find the area of rectangle and circle and volume of cuboid and sphere */

#include <iostream>
using namespace std;

// Class area to find the area of rectangle and circle
class area
{
private:
    float length, breadth, radius;

public:
    // Parameterized constructor
    area(float Length, float Breadth, float Radius)
    {
        length = Length;
        breadth = Breadth;
        radius = Radius;
    }
    // Friend functions declaration
    friend float rectangle(area);
    friend float circle(area);
};

// Inline functions
// Function to find the area of rectangle
inline float rectangle(area a1)
{
    if (a1.length == 0 && a1.breadth == 0)
    {
        a1.length = 1;
        a1.breadth = 1;
        return (a1.length * a1.breadth);
    }
    else
    {
        return (a1.length * a1.breadth);
    }
}

// Function to find the area of circle
inline float circle(area a1)
{
    if (a1.radius == 0)
    {
        a1.radius = 1;
        return 3.147;
    }
    else
    {
        return (3.147 * a1.radius * a1.radius);
    }
}

// Class to find the volume of the cuboid and sphere
class volume
{
private:
    float length, breadth, radius, height;

public:
    // Parameterized constructor
    volume(float Radius, float Height)
    {
        radius = Radius;
        height = Height;
    }

    // Function to find the volume of cuboid
    inline float cuboid(float height, area a1)
    {
        float areaRec;
        areaRec = rectangle(a1);

        if (height <= 0)
        {
            height = 1;
            return (areaRec * height);
        }
        else
        {
            return (1 * areaRec * height);
        }
    }

    // Function to find the volume of sphere
    inline float sphere(area a1)
    {
        float areaCircle;
        areaCircle = circle(a1);

        if (areaCircle == 3.147)
        {
            return (4 / 3) * 3.147;
        }
        else
        {
            return ((4.0 / 3.0) * areaCircle * radius);
        }
    }

    // Compare the volumes of cuboid1 and cuboid2
    inline float compareCuboid(area a1)
    {
        float volcub;
        volcub = this->cuboid(height, a1);
        return volcub;
    }

    // Compare the volumes of sphere1 and sphere2
    inline float compareSphere(float Radius, area a1)
    {
        float volsph;
        volsph = this->sphere(a1);
        return volsph;
    }

    // Prints the which cuboid or sphere has more volume
    inline float compareVolume(float volcub1, float volcub2, float volsph1, float volsph2)
    {
        if (volcub1 > volcub2)
        {
            cout << "Volume of cuboid1 is greater than cuboid2: " << volcub1 << endl;
        }
        else
        {
            cout << "Volume of cuboid2 is greater than cuboid1: " << volcub2 << endl;
        }
        if (volsph1 > volsph2)
        {
            cout << "Volume of sphere1 is greater than sphere2: " << volsph1 << endl;
        }
        else
        {
            cout << "Volume of sphere2 is greater than sphere1: " << volsph2 << endl;
        }
        return 3.0;
    }
};

// Main program
int main()
{
    float Radius, Length, Breadth, Height;
    int choice;
    float volcub1, volcub2, volsph1, volsph2;

    cout << "Enter the length, breadth, heigth and radius: " << endl;
    cin >> Length >> Breadth >> Height >> Radius;

    // Some boundary conditions
    if (Length <= Breadth)
    {
        cout << "The entered length is incorrect or greater than the breadth, please try again" << endl;
        cout << "Enter the length, breadth: " << endl;
        cin >> Length >> Breadth;
    }
    if (Height < 0)
    {
        cout << "Entered the height is incorrect, please try again" << endl;
        cout << "enter the height again: " << endl;
        cin >> Height;
    }
    if (Radius < 0)
    {
        cout << "Entered the radius is incorrect, please try again" << endl;
        cout << "enter the radius again: " << endl;
        cin >> Radius;
    }

    // Object creation
    area a1(Length, Breadth, Radius);
    volume v1(Radius, Height);

    // Menu
    while (1)
    {
        cout << endl;
        cout << "***** '1' to display area of rectangle *****" << endl;
        cout << "***** '2' to display area of circle *****" << endl;
        cout << "***** '3' to display volume of cuboid *****" << endl;
        cout << "***** '4' to display volume of sphere *****" << endl;
        cout << "***** '5' to compare volume of cuboid and sphere *****" << endl;
        cout << "***** '6' to exit *****" << endl;

        cout << "** Enter the choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Arear of rectangle: " << rectangle(a1) << endl;
            break;
        case 2:
            cout << "Area of circle: " << circle(a1) << endl;
            break;
        case 3:
            cout << "Volume of cuboid: " << v1.cuboid(Height, a1) << endl;
            break;
        case 4:
            cout << "Volume of sphere: " << v1.sphere(a1) << endl;
            break;
        case 5:
        {
            volsph1 = v1.compareSphere(Radius, a1);
            volcub1 = v1.compareCuboid(a1);

            // Asking user to enter the new values for comparing the volumes
            cout << "Enter the length, breadth, heigth and radius for new shapes for comparing: " << endl;
            cin >> Length >> Breadth >> Height >> Radius;

            // New object creation
            area a2(Length, Breadth, Radius);
            volume v2(Radius, Height);

            volsph2 = v2.compareSphere(Radius, a2);
            volcub2 = v2.compareCuboid(a2);
            v2.compareVolume(volcub1, volcub2, volsph1, volsph2);
            break;
        }
        case 6:
            exit(0);
        }
    }

    return 0;
}