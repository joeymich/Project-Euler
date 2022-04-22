// Problem 48 -- Self powers
#include <iostream>
#include <vector>
using namespace std;

void selfPower(unsigned int n, vector<unsigned int>& v);
void add(vector<unsigned int> &s, vector<unsigned int>& t);

int main()
{
    vector<unsigned int> sum(10, 0);
    for (unsigned int i = 1; i <= 1000; i++)
    {
        vector<unsigned int> v(10);
        selfPower(i, v);
        add(sum, v);
    }
    for (auto it = sum.begin(); it != sum.end(); it++)
        cout << *it;
    return 0;
}

void selfPower(unsigned int n, vector<unsigned int>& v)
{
    fill(v.begin(), v.end() - 1, 0);
    v.at(9) = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int c = 0;
        for (auto rit = v.rbegin(); rit != v.rend(); rit++)
        {
            *rit = *rit * n + c;
            if (*rit > 9)
            {
                c = *rit / 10;
                *rit %= 10;
            }
            else
                c = 0;
        }
    }
}

void add(vector<unsigned int> &s, vector<unsigned int>& t)
{
    unsigned int c = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        s.at(i) += t.at(i) + c;
        if (s.at(i) > 9)
        {
            c = s.at(i) / 10;
            s.at(i) = s.at(i) % 10;
        }
        else
            c = 0;
    }
}