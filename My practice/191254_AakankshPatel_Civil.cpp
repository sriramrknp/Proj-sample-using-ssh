#include <bits/stdc++.h>
using namespace std;
typedef double dbl;

dbl xVal1 = 1.0, xVal2 = 0.8;
vector<dbl> fn, y_n;
dbl f_n[4], K[4], k[2], h;

dbl f(dbl x, dbl y)
{
    return -2 * x - y;
}

dbl AB4OrderFormula()
{
    return y_n[y_n.size() - 1] + (h / 24) * (55 * f_n[3] - 59 * f_n[2] + 37 * f_n[1] - 9 * f_n[0]);
}

dbl RK4OrderFormula()
{
    return y_n[y_n.size() - 1] + (1 / 6) * (K[0] + 2 * K[1] + 2 * K[2] + K[3]);
}

dbl RK2OrderFormula()
{
    return y_n[y_n.size() - 1] + (1 / 2) * (k[0] + k[1]);
}
int main()
{
    dbl x0 = 0, y0 = -1;
    y_n.push_back(y0);
    cout << "Enter the value h:\n";
    cin >> h;
    int method, RKorder = 0;
    cout << "Enter 1 for using Euler method, 2 for using RK method: \n";
    cin >> method;
    int temp = 0;
    dbl yNext, xCur = x0, yCur = y0;
    if (method == 1)
    {
        // implement Euler method
        // getting f0,f1,f2,f3  and y0,y1,y2,y3..
        while (temp < 3)
        {
            cout << "Inside while temp loop \n";
            dbl fVal = f(xCur, yCur);
            yNext = yCur + (h * fVal);
            fn.push_back(fVal);
            f_n[temp++] = fVal;
            y_n.push_back(yNext);
            xCur += h;
            yCur = yNext;
        }
        f_n[temp++] = f(xCur, yCur);
    }

    else if (method == 2)
    {
        // implement RK method
        cout << "Enter which RK order method to use: ";
        cin >> RKorder;
        if (RKorder == 4)
        {
            // 4th order
            // getting f0,f1,f2,f3  and y0,y1,y2,y3..
            while (temp < 3)
            {
                K[0] = h * f(xCur, yCur);
                K[1] = h * f(xCur + h / 2, yCur + K[0] / 2);
                K[2] = h * f(xCur + h / 2, yCur + K[1] / 2);
                K[3] = h * f(xCur + h, yCur + K[2]);
                dbl yNext = RK4OrderFormula();
                y_n.push_back(yNext);

                // simultaneously finding fns..
                dbl fVal = f(x0 + (h * temp), yCur);
                fn.push_back(fVal);
                f_n[temp++] = fVal;
                xCur += h;
                yCur = y_n[y_n.size() - 1];
            }
            f_n[temp++] = f(xCur, yCur);
        }
        else if (RKorder == 2)
        {
            // 2nd order one
            // getting f0,f1,f2,f3  and y0,y1,y2,y3..
            while (temp < 3)
            {
                k[0] = h * f(xCur, yCur);
                k[1] = h * f(xCur + h, yCur + k[0]);
                dbl yNext = RK2OrderFormula();
                y_n.push_back(yNext);

                // simultaneously finding fns..
                dbl fVal = f(x0 + (h * temp), yCur);
                fn.push_back(fVal);
                f_n[temp++] = fVal;
                xCur += h;
                yCur = y_n[y_n.size() - 1];
            }
            f_n[temp++] = f(xCur, yCur);
        }
    }
    if (method == 1)
        yNext = AB4OrderFormula();
    else if (method == 2 && RKorder == 4)
        yNext = RK4OrderFormula();
    else if (method == 2 && RKorder == 2)
        yNext = RK2OrderFormula();
    y_n.push_back(yNext);
    dbl reqPoint = x0 + (h * temp);
    while (reqPoint < xVal2)
    {
        dbl fVal = f(reqPoint, y_n[y_n.size() - 1]);
        f_n[0] = f_n[1];
        f_n[1] = f_n[2];
        f_n[2] = f_n[3];
        f_n[3] = fVal;
        fn.push_back(fVal);
        if (method == 1)
            yNext = AB4OrderFormula();
        else if (method == 2 && RKorder == 4)
            yNext = RK4OrderFormula();
        else if (method == 2 && RKorder == 2)
            yNext = RK2OrderFormula();
        y_n.push_back(yNext);
        reqPoint += h;
    }
    cout << "y at x=0.8 is : " << y_n[y_n.size() - 1] << "\n";
    while (reqPoint < xVal1)
    {
        dbl fVal = f(reqPoint, y_n[y_n.size() - 1]);
        f_n[0] = f_n[1];
        f_n[1] = f_n[2];
        f_n[2] = f_n[3];
        f_n[3] = fVal;
        fn.push_back(fVal);
        if (method == 1)
            yNext = AB4OrderFormula();
        else if (method == 2 && RKorder == 4)
            yNext = RK4OrderFormula();
        else if (method == 2 && RKorder == 2)
            yNext = RK2OrderFormula();
        y_n.push_back(yNext);
        reqPoint += h;
    }
    cout << "y at x=1.0 is : " << y_n[y_n.size() - 1] << "\n";
    return 0;
}