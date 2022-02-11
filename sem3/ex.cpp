#include <iostream> 
using namespace std;

class integer
{
    int i;
    public:
    integer( int _i) : i(_i) {}
    void change_i ( int _i)  {i = _i;}
    int get_i()  {return i;}

};

int main ()
{
    integer obj(10);
    obj.change_i(5);
    cout << obj.get_i();
    return 0;
}