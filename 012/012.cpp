// Problem 12 -- Highly divisible triangular number
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prime_factors(unsigned int n)
{
    vector<int> primes;
    while (n % 2 == 0) {
        primes.push_back(2);
        n /= 2;
    }
    for (unsigned int i = 3; i < sqrt(n); i += 2) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 3)
        primes.push_back(n);
    return primes;
}

vector<int> exponents_from_primes(vector<int> primes)
{
    vector<int> exponents;
    unsigned int count = 1;
    if (primes.size() == 1) {
        exponents.push_back(1);
        return exponents;
    }
    for (unsigned int i = 1; i < primes.size(); i++) {
        if (primes[i] == primes[i - 1])
            count++;
        else {
            exponents.push_back(count);
            count = 1;
        }
        if (count == 1 && i == primes.size() - 1)
            exponents.push_back(count);
    }
    return exponents;
}

int factors_from_exponents(vector<int> exponents)
{
    unsigned int factors = 1;
    for (unsigned int i = 0; i < exponents.size(); i++)
        factors *= (exponents[i] += 1);
    return factors;
}

int num_divisors(int n)
{
    return factors_from_exponents(exponents_from_primes(prime_factors(n)));
}

int main()
{
    unsigned long long tri_num = 0;
    unsigned long long nat_num = 0;
    unsigned long long solution;
    while(true) {
        nat_num++;
        tri_num += nat_num;
        if (num_divisors(tri_num) > 500) {
            solution = tri_num;
            break;
        }
    }
    cout << solution << "\n";
}