// Problem 2 -- Even Fibonacci numbers
#include <iostream>
using namespace std;

int main()
{
    unsigned int last1 = 1;
    unsigned int last2 = 0;
    unsigned int fib = 0;
    unsigned int sum = 0;
    while (fib < 4000000) {
        fib = last1 + last2;
        if (fib % 2 == 0) {
            sum += fib;
        } 
        last2 = last1;
        last1 = fib;
    }
    cout << sum;
    return 0;
}