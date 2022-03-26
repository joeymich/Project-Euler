// Problem 7 -- 10001st prime
#include <iostream>
using namespace std;

int main()
{
    unsigned int count = 0;
    unsigned int i = 0;
    unsigned int prime;
    unsigned int sol;
    while (count != 10001) {
        bool isPrime = true;
        if (i == 0 || i == 1) {
            isPrime = false;
        }
        else {
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            count++;
            prime = i;
        }
        i++;
    }
    sol = i - 1;
    cout << sol << endl;
    return 0;
}