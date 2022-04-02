// Problem 21 -- Amicable numbers
#include <iostream>
#include <vector>
#include <map>
using namespace std;

unsigned int d(unsigned int a)
{
    vector<unsigned int> v;
    for (unsigned int i = 1; i <= a / 2; i++)
        if (a % i == 0)
            v.push_back(i);
    unsigned int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++)
        sum += v.at(i);
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