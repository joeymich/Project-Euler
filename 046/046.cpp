// Problem 46 -- Goldbach's other conjecture
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned int n);

int main()
{
    unsigned int n = 35;
    bool goldbach = true;
    while(goldbach)
    {
        if (isPrime(n))
        {
            n += 2;
            continue;
        }
        goldbach = false;
        unsigned int root = 1;
        while (int(n - 2 * root * root) > 0)
        {
            if (isPrime(n - 2 * root * root))
                goldbach = true;
            root++;
        }
        if (!goldbach)
            break;
        n+=2;
    }
    cout << n << "\n";
    return 0;
}

bool isPrime(unsigned int n)
{
    if (n == 2)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;
    for (unsigned int i = 3; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}