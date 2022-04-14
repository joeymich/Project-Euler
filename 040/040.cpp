// Problem 40 -- Champernowne's constant
#include <iostream>
using namespace std;

unsigned int d(unsigned int n);
unsigned int length(unsigned int n);

int main()
{
    cout << d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000) << "\n";
    return 0;
}

unsigned int d(unsigned int n)
{
    unsigned int place = 1;
    unsigned int num = 1;
    while (place < n)
    {
        num++;
        place += length(num);
    }
    unsigned int temp = num;
    for (unsigned int i = 0; i < place - n + 1; i++)
    {
        temp = num % 10;
        num /= 10;
    }
    return temp;
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