// Problem 55 -- Lychrel numbers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void set(vector<unsigned int>& v, unsigned int n);
void add(vector<unsigned int>& v1, vector<unsigned int>& v2);
bool isPalindromic(vector<unsigned int>& v);

int main()
{
    unsigned int count = 0;
    for (unsigned int i = 1; i < 10000; i++)
    {
        vector<unsigned int> v1;
        set(v1, i);
        for (unsigned int j = 0; j < 50; j++)
        {
            vector<unsigned int> v2 = v1;
            reverse(v2.begin(), v2.end());
            add(v1, v2);
            if (isPalindromic(v1))
                break;
            if (j == 49)
                count++;
        }
    }
    cout << count << "\n";
    return 0;
}

void set(vector<unsigned int>& v, unsigned int n)
{
    while (n != 0)
    {
        v.insert(v.begin(), n % 10);
        n /= 10;
    }
}

void add(vector<unsigned int>& v1, vector<unsigned int>& v2)
{
    unsigned int c = 0;
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        v1.at(i) += v2.at(i) + c;
        if (v1.at(i) > 9)
        {
            c = v1.at(i) / 10;
            v1.at(i) %= 10;
        }
        else
        {
            c = 0;
        }
        if (i == 0 && c != 0)
            v1.insert(v1.begin(), c);
    }
}

bool isPalindromic(vector<unsigned int>& v)
{
    vector<unsigned int> v2 = v;
    reverse(v2.begin(), v2.end());
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v.at(i) != v2.at(i))
            return false;
    }
    return true;
}