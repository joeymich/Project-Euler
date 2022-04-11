// Problem 36 -- Double-base palindroms
#include <iostream>
#include <vector>
using namespace std;

bool palindromic(unsigned int n);
bool palindromic(vector<unsigned int> v);
vector<unsigned int> toBinary(unsigned int n);

int main()
{
    unsigned long long sum = 0;
    for (unsigned int i = 1; i < 1000000; i++)
        if (palindromic(i) && palindromic(toBinary(i)))
            sum += i;
    cout << sum << "\n";
}

bool palindromic(unsigned int n)
{
    unsigned long long temp = n;
    unsigned long long rev = 0;
    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    if (n == rev)
        return true;
    return false;
}

bool palindromic(vector<unsigned int> v)
{
    vector<unsigned int> rcopy;
    for (auto rit = v.rbegin(); rit != v.rend(); rit++)
        rcopy.push_back(*rit);
    for (unsigned int i = 0; i < v.size(); i++)
        if (v.at(i) != rcopy.at(i))
            return false;
    return true;
}

vector<unsigned int> toBinary(unsigned int n)
{
    vector<unsigned int> v;
    while (n != 0)
    {
        v.insert(v.begin(), n % 2);
        n /= 2;
    }
    return v;
}