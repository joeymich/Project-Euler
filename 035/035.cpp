// Problem 35 -- Circular primes
#include <iostream>
#include <cmath>
using namespace std;

bool isCircularPrime(unsigned int n);
unsigned int numDigits(unsigned int n);
bool isPrime(unsigned int n);

int main()
{
    unsigned int count = 0;
    for (unsigned int i = 1; i < 1000000; i++)
        if (isCircularPrime(i))
            count++;
    cout << count << "\n";
    return 0;
}

bool isCircularPrime(unsigned int n)
{
    unsigned int length = numDigits(n);
    for (unsigned int i = 0; i < length; i++)
    {
        n = (n % 10) * pow(10, length - 1) + n / 10;
        if (!isPrime(n))
            return false;
    }
    return true;
}

unsigned int numDigits(unsigned int n)
{
    unsigned int length = 0;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return length;
}

bool isPrime(unsigned int n)
{
    if (n == 0 || n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (unsigned int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}