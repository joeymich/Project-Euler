// Problem 43 -- Sub-string divisibility
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "0123456789";
    unsigned long long sum = 0;
    do
    {
        if (stoi(s.substr(1, 3)) % 2 != 0)
            continue;
        if (stoi(s.substr(2, 3)) % 3 != 0)
            continue;
        if (stoi(s.substr(3, 3)) % 5 != 0)
            continue;
        if (stoi(s.substr(4, 3)) % 7 != 0)
            continue;
        if (stoi(s.substr(5, 3)) % 11 != 0)
            continue;
        if (stoi(s.substr(6, 3)) % 13 != 0)
            continue;
        if (stoi(s.substr(7, 3)) % 17 != 0)
            continue;
        sum += stoll(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << sum << "\n";
    return 0;
}