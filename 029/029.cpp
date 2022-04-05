// Problem 29 -- Distinct powers
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void multiply(vector<unsigned int>& v, unsigned int n);

int main()
{
    set<vector<unsigned int>> s;
    for (unsigned int i = 2; i <= 100; i++)
        for (unsigned int j = 2; j <= 100; j++)
        {
            vector<unsigned int> temp = {1};
            for (unsigned int k = 0; k < j; k++)
                multiply(temp, i);
            s.insert(temp);
        }
    cout << s.size() << "\n";
    return 0;
}

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