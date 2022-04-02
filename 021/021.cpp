// Problem 21 -- Amicable numbers
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

unsigned int d(unsigned int a)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= sqrt(a); i++)
        if (a % i == 0)
        {
            if (a / i == i)
                sum += i;
            else
                sum += i + a / i;
        }
    sum -= a;
    return sum;
}

int main()
{
    map<unsigned int, unsigned int> mp;
    for (unsigned int i = 1; i < 10000; i++)
        mp[i] = d(i);
    unsigned int sum = 0;
    for (unsigned int i = 1; i < 10000; i++)
    {
        unsigned int temp = mp[i];
        if (temp > 0 && temp < 10000 && temp != i && mp[temp] == i)
            sum += i;
    }
    cout << sum << "\n";
    return 0;
}