#include<iostream>
#include<string>

int main()
{
    std::string dna;
    long int count1=0,count2=0;
    std::cin >> dna;
    for (long int i = 0; i < dna.length(); i++)
    {
        if(dna[i] == dna[i+1])
        {
            count1++;
        }
        else
            count1 = 0;
        if (count1 > count2)
            count2 = count1;
        //count1 = 0;
    }
    std::cout << count2+1;

    return 0;
}