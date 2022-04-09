// Problem 34 -- Digit factorials
#include <iostream>
using namespace std;

unsigned int fact(unsigned int n);

int main()
{
    unsigned long long sum = 0;
    for (unsigned int i = 10; i < 10000000; i++)
    {
        unsigned int tempI = i;
        unsigned int tempSum = 0;
        while (tempI != 0)
        {
            tempSum += fact(tempI % 10);
            tempI /= 10;
        }
        if (tempSum == i)
            sum += i;
    }
    cout << sum << "\n";
    return 0;
}

unsigned int fact(unsigned int n)
{
    unsigned int fact = 1;
    for (unsigned int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}