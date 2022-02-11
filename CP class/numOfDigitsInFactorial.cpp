#include <iostream>
#include <ctime>
#include<math.h>

int main()
{
    clock_t start, end;
    start = clock();

    // your code goes here
    long long int T;
    std::cin >> T;
    long long int sum = 0;
    while (T > 0)
    {
        long long int N;
        std::cin >> N;
        double j = 0;

        for (int i = 2; i <= N;i++)
        {
            j += log(i);
        }
        std::cout << int(j/log(10))+1 << '\n';
        T--;
    }


    end = clock();

    //Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << time_taken << '\n';
    return 0;
}