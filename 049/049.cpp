// Problem 49 -- Prime permutations
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(unsigned int n);

int main()
{
    vector<unsigned int> ignore = {1487};
    vector<unsigned int> solution;
    for (unsigned int n = 1000; n < 10000; n++)
    {
        string s = to_string(n);
        vector<unsigned int> v;
        do
        {
            int t = stoi(s);
            if (count(ignore.begin(), ignore.end(), t))
                continue;
            if (isPrime(t))
                v.push_back(t);
        } while (next_permutation(s.begin(), s.end()));
        if (v.size() >= 3)
        {
            sort(v.begin(), v.end());
            for (size_t i = 0; i < v.size(); i++)
                for (size_t j = i + 1; j < v.size(); j++)
                    for (size_t k = j + 1; k < v.size(); k++)
                        if (v.at(j) - v.at(i) == v.at(k) - v.at(j))
                        {
                            solution = {v.at(i), v.at(j), v.at(k)};
                            goto end;
                        }
        }
    }
    end:
        for (auto it = solution.begin(); it != solution.end(); it++)
            cout << *it;
    return 0;
}

bool isPrime(unsigned int n)
{
    if (n == 2)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;
    for (unsigned int i = 3; i <= sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}