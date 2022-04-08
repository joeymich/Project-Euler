// Problem 26 -- Reciprocal cycles
#include <iostream>
#include <set>
using namespace std;

size_t repetend_length(unsigned int d);

int main()
{
    size_t maxLength = 0;
    unsigned int maxD = 1;
    for (unsigned int i = 1; i < 1000; i++)
    {
        size_t temp = repetend_length(i);
        if (temp > maxLength)
        {
            maxLength = temp;
            maxD = i;
        }
    }
    cout << maxD << "\n";
}

size_t repetend_length(unsigned int d)
{
    int rem = 1 % d;
    set<int> s;
    while (rem != 0)
    {
        if(s.find(rem) != s.end())
            break;
        s.insert(rem);
        rem = (rem * 10) % d;
    }
    return s.size();
}