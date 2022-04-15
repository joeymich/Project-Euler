// Problem 41 -- Pandigital prime
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool isPrime(unsigned int n);

int main()
{
    unsigned int max = 0;
    set<unsigned int> s = {1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
    for (auto it = s.begin(); it != s.end(); it++)
    {
        string s = to_string(*it);
        do
        {
            unsigned int temp = stoi(s);
            if (isPrime(temp))
                if (temp > max)
                    max = temp;
        } while (next_permutation(s.begin(), s.end()));
    }
    cout << max << "\n";
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