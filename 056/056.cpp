// Problem 56 -- Powerful digit sum
#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> power(unsigned int a, unsigned int b);
void multiply(vector<unsigned int>& v, unsigned int n);
unsigned int sumDigits(vector<unsigned int>& v);

int main()
{
    unsigned int max = 0;
    for (unsigned int i = 1; i < 100; i++)
        for (unsigned int j = 1; j < 100; j++)
        {
            vector<unsigned int> v = power(i, j);
            unsigned int temp = sumDigits(v);
            if (temp > max)
                max = temp;
        }
    cout << max << endl;
    return 0;
}

vector<unsigned int> power(unsigned int a, unsigned int b)
{
    vector<unsigned int> v = {1};
    for (unsigned int i = 0; i < b; i++)
        multiply(v, a);
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

unsigned int sumDigits(vector<unsigned int>& v)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < v.size(); i++)
        sum += v.at(i);
    return sum;
}