// Problem 063 -- Powerful digit counts
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

unsigned int length(unsigned long long n);
vector<unsigned int> power(unsigned int n, unsigned int p);
void multiply(vector<unsigned int>& v, unsigned int n);

int main()
{
    unsigned int count = 0;
    unsigned long long n = 1;
    unsigned int p = 1;
    vector<unsigned int> num;
    while (p <= 21)
    {
        while (num.size() <= p)
        {
            num = power(n, p);
            if (num.size() == p)
                count++;
            n++;
        }
        n = 1;
        p++;
    }
    cout << count << "\n";
    return 0;
}

vector<unsigned int> power(unsigned int n, unsigned int p)
{
    vector<unsigned int> v = {1};
    for (unsigned int i = 0; i < p; i++)
        multiply(v, n);
    return v;
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