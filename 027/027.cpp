// Problem 27 -- Quadratic primes
#include <iostream>
#include <cmath>
using namespace std;

unsigned int consecutivePrimes(int a, int b);
bool isPrime(int a);

int main()
{
    int aMax, bMax;
    unsigned int max = 0;
    for (int a = -999; a < 1000; a++)
        for (int b = -1000; b <= 1000; b++)
        {
            unsigned int temp = consecutivePrimes(a, b);
            if (temp > max)
            {
                max = temp;
                aMax = a;
                bMax = b;
            }
        }
    cout << aMax * bMax << "\n";
    return 0;
}

unsigned int consecutivePrimes(int a, int b)
{
    int n = 0;
    while (isPrime(n * n + a * n + b))
        n++;
    return n;
}

bool isPrime(int a)
{
    if (a <= 1 || a % 2 == 0)
        return false;
    else
        for (unsigned int i = 3; i <= sqrt(a); i+=2)
            if (a % i == 0)
                return false;
    return true;
}