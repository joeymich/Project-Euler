// Problem 3 -- Largest prime factor
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long long n = 600851475143;
    vector<int> primes(0);
    while (n % 2 == 0) {
        primes.push_back(2);
        n /= 2;
    }
    for (int i = 3; i < sqrt(n); i += 2) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        primes.push_back(n);
    }
    sort(primes.begin(), primes.end());
    cout << primes.back() << endl;
    return 0;
}