// Problem 10 -- Summation of primes
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long answer = 0;
    unsigned int i = 0;
    while (i < 2000000) {
        bool isPrime = true;
        if (i == 0 || i == 1)
            isPrime = false;
        else if (i % 2 == 0)
            isPrime = false;
        else {
            for (unsigned int j = 3; j <= sqrt(i); j+=2) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            answer += i;
        i++;
    }
    cout << answer << endl;
    return 0;
}