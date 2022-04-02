// Problem 23 -- Non-abundant sums
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
            else{
                sum += i;
                sum += a / i;
            }
        }
    sum -= a;
    return sum;
}

int main()
{
    map<unsigned int, unsigned int> mp1;
    for (unsigned int i = 1; i < 28123; i++)
        mp1[i] = d(i);
    map<unsigned int, bool> mp2;
    for (unsigned int i = 1; i < 28123; i++)
        mp2[i] = mp1[i] <= i ? false : true;
    bool sumAbundant;
    unsigned int sum = 0;
    for (unsigned int i = 1; i < 28123; i++)
    {
        sumAbundant = false;
        for (unsigned int j = 1; j < i / 2 + 1; j++)
        {
            if (mp2[j] && mp2[i-j])
            {
                sumAbundant = true;
                break;
            }
        }
        if (!sumAbundant)
            sum += i;
    }
    cout << sum << "\n";
    return 0;
}