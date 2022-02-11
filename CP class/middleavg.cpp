#include<iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    long int avg = 0;

    if(str.length()%2==0){
        avg = ((str[str.length()/2] - 48) + (str[(str.length())/2 - 1] - 48)) / 2;
    }else
        avg = ((str[(str.length()) / 2] - 48) + (str[(str.length()) / 2 - 1] - 48) + (str[(str.length()) / 2 + 1] - 48)) / 3;

    cout << avg;
    return 0;
}