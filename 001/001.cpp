// Problem 1 -- Multiples of 3 or 5
#include <iostream>
using namespace std;

int main()
{
    unsigned long long sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (((i % 3) == 0) || ((i % 5) == 0)) {
            sum += i;
        }
    }
    cout << sum << "\n";
    return 0;
} 