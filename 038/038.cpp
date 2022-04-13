// Problem 38 -- Pandigital multiples
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

unsigned int pandigital(unsigned int n);
unsigned int length(unsigned int n);

int main()
{
    unsigned int max = 0;
    for (unsigned int i = 1; i < 9999; i++)
    {
        unsigned int temp = pandigital(i);
        if (temp != 0)
            if (temp > max)
                max = temp;
    }
    cout << max << "\n";
}

unsigned int pandigital(unsigned int n)
{
    unsigned int totalLength = 0, m = 1, pan = 0;
    set<unsigned int> digits;
    while (totalLength < 9)
    {
        unsigned int temp = n * m;
        unsigned int len = length(temp);
        totalLength += len;
        pan += temp * pow(10, 9 - totalLength);
        for (unsigned int i = 0; i < len; i++)
        {
            unsigned int digit = temp % 10;
            if (digits.find(digit) == digits.end())
                digits.insert(digit);
            else
                return 0;
            temp /= 10;
        }
        m++;
    }
    if (digits.find(0) != digits.end() || digits.size() != 9)
        return 0;
    return pan;
}

unsigned int length(unsigned int n)
{
    unsigned int len = 0;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return len;
}