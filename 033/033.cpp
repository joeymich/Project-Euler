// Problem 33 -- Digit cancelling fractions
#include <iostream>
#include <vector>
using namespace std;

unsigned int getGCD(unsigned int a, unsigned int b);

int main()
{
    vector<unsigned int> numerators;
    vector<unsigned int> denominators;
    for (unsigned int i = 10; i < 100; i++)
        for (unsigned int j = 10; j < 100; j++)
        {
            if (i == j)
                continue;
            if (i % 10 == j / 10)
                if ((float)(i / 10) / (j % 10) == (float)i / j)
                {
                    numerators.push_back(i / 10);
                    denominators.push_back(j % 10);
                }
        }
    unsigned int num = 1;
    unsigned int den = 1;
    for (size_t i = 0; i < numerators.size(); i++)
    {
        num *= numerators.at(i);
        den *= denominators.at(i);
    }
    cout << den / getGCD(num, den) << "\n";
    return 0;
}

unsigned int getGCD(unsigned int a, unsigned int b)
{
    return b == 0 ? a : getGCD(b, a % b);
}