// Problem 58 -- Spiral primes
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned int n);

int main()
{
    unsigned int n = 1;
    unsigned int primes = 0;
    float primesRatio = 1.0;
    while (primesRatio > 0.1)
    {
        n += 2;
        if (isPrime(n * n))
            primes++;
        if (isPrime(n * n - 1 * (n - 1)))
            primes++;
        if (isPrime(n * n - 2 * (n - 1)))
            primes++;
        if (isPrime(n * n - 3 * (n - 1)))
            primes++;
        primesRatio = (float)primes / (n * 2 - 1);
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
    for (unsigned int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}