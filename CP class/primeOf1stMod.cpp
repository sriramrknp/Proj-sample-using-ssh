#include <iostream>
#include <vector>

int main()
{
    long long int num;
    std::cin >> num;

    std::vector<bool> prime(num + 1, true);

    prime[0] = prime[1] = false;
    for (long long int i = 2; (i * i) <= num;i++)
    {
        if(prime[i]){
            for (long int j = i * i; j <= num;j+=i){
                prime[j] = false;
            }
        }
    }
    long long int count = 0;

    for (long long int i = 0; i <= num;i++)
    {
        if(prime[i])
        {
            count++;
            if((count-1)%100==0)
            {
                std::cout << i << " ";
            }
        }
    }
    

    return 0;
}