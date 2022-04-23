// Problem 50 -- Consecutive prime sum
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;

bool isPrime(unsigned int n);

int main()
{
    vector<unsigned int> primes;
    unsigned int maxLength = 0;
    unsigned int maxPrime = 0;
    for (unsigned int i = 0; i < 10000; i++)
        if (isPrime(i))
            primes.push_back(i);
    for (unsigned int i = 0; i < 4; i++)
    {
        int sum = 0;
        int length = 0;
        for (unsigned int j = i; j < primes.size(); j++)
        {
            sum += primes.at(j);
            if (sum > 1000000)
                continue;
            length++;
            if (isPrime(sum))
            {
                if (length > maxLength)
                {
                    maxLength = length;
                    maxPrime = sum;
                }
            }
        }
    }
    cout << maxPrime << "\n";
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