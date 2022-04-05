// Problem 30 -- Digit fifth powers
#include <iostream>
using namespace std;

int main()
{
    unsigned int i = 2;
    unsigned int sum = 0;
    while(i < 1000000){
        unsigned int a = i;
        unsigned int temp = 0;
        while (a != 0)
        {
            unsigned int b = a % 10;
            a /= 10;
            temp += b * b * b * b * b;
        }
        if (i == temp)
            sum += i;
        i++;
    }
    cout << sum << "\n";
    return 0;
}