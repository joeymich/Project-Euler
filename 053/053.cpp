// Problem 53 -- Combinatoric selections
#include <iostream>
using namespace std;

unsigned long long c(unsigned int n, unsigned int r);

int main()
{
    unsigned int count = 0;
    for (unsigned int i = 1; i <= 100; i++)
        for (unsigned int j = 1; j <= i; j++)
            if (c(i, j) > 1000000)
                count++;
    cout << count << "\n";
    return 0;
}

unsigned long long c(unsigned int n, unsigned int r)
{
    if (r > n - r)
        r = n - r;
    unsigned long long num = 1;
    for (unsigned int i = 1; i <= r; i++)
    {
        num *= n - r + i;
        num /= i;
    }
    return num;
}