// Problem 20 -- Factorial digit sum
#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<unsigned int>& v, unsigned int n)
{
    unsigned int p = 0;
    unsigned int c = 0;
    for (auto rit = v.rbegin(); rit != v.rend(); rit++)
    {
        p = (*rit) * n + c;
        c = p / 10;
        *rit = p % 10;
    }
    while (c > 0)
    {
        v.insert(v.begin(), c % 10);
        c /= 10;
    }
}

int main()
{
    vector<unsigned int> fact = {1};
    for (unsigned int i = 1; i <= 100; i++)
        multiply(fact, i);
    unsigned int sum = 0;
    for (unsigned int i = 0; i < fact.size(); i++)
        sum += fact.at(i);
    cout << sum << "\n";
    return 0;
}