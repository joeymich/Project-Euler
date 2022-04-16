// Problem 44 -- Pentagon numbers
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<unsigned int> s;
    for (unsigned int i = 1; i < 5000; i++)
        s.insert(i * (3 * i - 1) / 2);
    for (auto it1 = s.begin(); it1 != s.end(); it1++)
        for (auto it2 = next(it1, 1); it2 != s.end(); it2++)
            if (s.find(*it2 - *it1) != s.end() && s.find(*it1 + *it2) != s.end())
                cout << *it2 - *it1 << "\n";
    return 0;
}