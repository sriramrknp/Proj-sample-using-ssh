#include<iostream>
using namespace std;
int main() {
    int x = 6;
   cout << "\033[1;31mThis is bold red text\033[0m\n";
   cout << "\033[;32mGreen Text\033[0m\n";
   cout << "\033[4;33mYellow underlined text\033[0m\n";
   cout << "\033[;34mBlue text\033[0m\n";

   cout << "\033[;34m x \033[0m\n" << x;

   return 0;
}