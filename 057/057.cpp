// Problem 57 -- Square root convergents
#include <iostream>
using namespace std;

unsigned int length(unsigned int n);

int main()
{
    unsigned int num = 3;
    unsigned int den = 2;
    unsigned int count = 0;
    for (unsigned int i = 0; i < 999; i++)
    {
        num += den;
        int temp = num;
        num = den;
        den = temp;
        num += den;
        cout << num << " " << den << endl;
        if (length(num) > 7)
        {
            num /= 10;
            den /= 10;
        }
        if (length(num) > length(den))
            count++;
    }
    cout << count << endl;
    return 0;
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