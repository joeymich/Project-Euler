// Problem 37 -- Truncatable primes
#include <iostream>
#include <cmath>
using namespace std;

bool isTruncPrime(unsigned int n);
bool isPrime(unsigned int n);
unsigned int length(unsigned int n);

int main()
{
    unsigned int i = 10, count = 0, sum = 0;
    while (count != 11)
    {
        if (isTruncPrime(i))
        {
            sum += i;
            count++;
        }
        i++;
    }
    cout << sum << "\n";
}

bool isTruncPrime(unsigned int n)
{
    if (!isPrime(n))
        return false;
    unsigned int len = length(n);
    for (unsigned int j = 1; j < len; j++)
        if (!isPrime(n / pow(10, j)))
            return false;
    for (unsigned int j = 0; j < len - 1; j++)
        if (!isPrime(n % (int)pow(10, j+1)))
            return false;
    return true;
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

unsigned int length(unsigned int n)
{
    unsigned int length = 0;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return length;
}