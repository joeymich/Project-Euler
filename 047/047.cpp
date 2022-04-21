// Problem 47 -- Distinct primes factors
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<unsigned int, unsigned int> primeFactors(unsigned int n);
bool distinctFactors(map<unsigned int, unsigned int>& mp1, map<unsigned int, unsigned int>& mp2);

int main()
{
    unsigned int i = 3;
    while(1)
    {
        auto f1 = primeFactors(i);
        auto f2 = primeFactors(i+1);
        auto f3 = primeFactors(i+2);
        auto f4 = primeFactors(i+3);
        if (f1.size() == 4 && f2.size() == 4 && f3.size() == 4 && f4.size() == 4)
            if (distinctFactors(f1, f2) && distinctFactors(f1, f3) && distinctFactors(f2, f3) && distinctFactors(f1, f4) && distinctFactors(f2, f4) && distinctFactors(f3, f4))
                break;
        i++;
    }
    cout << i << "\n";
    return 0;
}

map<unsigned int, unsigned int> primeFactors(unsigned int n)
{
    map<unsigned int, unsigned int> mp;
    while (n % 2 == 0)
    {
        if (mp.find(2) == mp.end())
            mp[2] = 1;
        else
            mp[2] += 1;
        n /= 2;
    }
    for (unsigned int i = 3; i <= sqrt(n); i += 2)
        while (n % i == 0)
        {
            if (mp.find(i) == mp.end())
                mp[i] = 1;
            else
                mp[i] += 1;
            n /= i;
        }
    if (n > 2)
        mp[n] = 1;
    return mp;
}

bool distinctFactors(map<unsigned int, unsigned int>& mp1, map<unsigned int, unsigned int>& mp2)
{
    for (auto it = mp1.begin(); it != mp1.end(); it++)
        if (mp2.find(it->first)->second == it->second)
            return false;
    return true;
}