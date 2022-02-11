#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
   // msg.assign(size_t __n, const __1::string &__u);

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}