#include <iostream>
#include <stdlib.h>
#include <string>
//#include "colour"
#include <climits>
using namespace std;

class stringsSorting
{
    public: 

    void bubbbleSort_Strings(string *words, int n)
    {
        cout << "\033[4;33mEnter \033[0m" << n << "\033[4;33m different strings: \033[0m\n";
        //cout << "Enter the string: " << endl;
        for (int i = 0; i < n; i++)
            getline(cin >> ws, words[i]);

        string temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                //comparing two consecutive elements if left element is greater than right element then swap
                if (words[j] > words[j + 1])
                {

                    temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                }
            }
        }
    }
};

int
main()
{
    int n = 4;
    string words[n];

    stringsSorting ss1;
    ss1.bubbbleSort_Strings(words, n);

    //system("Color 0A");

    for (int i = 0; i < n; i++)
        cout << " " << words[i];

    // cout << words.length();
    return 0;
}