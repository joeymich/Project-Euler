// Problem 32 -- Pandigital products
#include <iostream>
#include <set>
using namespace std;

bool hasPandigital(unsigned int n);

int main()
{
    unsigned long long sum = 0;
    for (unsigned int i = 1; i < 10000; i++)
        if (hasPandigital(i))
            sum += i;
    cout << sum << "\n";
    return 0;
}

bool hasPandigital(unsigned int n)
{
    for (unsigned int i = 1; i <= n; i++)
        if (n % i == 0)
        {
            multiset<unsigned int> ms;
            unsigned int tempN = n;
            unsigned int tempI = i;
            unsigned int tempJ = n/i;
            while (tempN != 0)
            {
                ms.insert(tempN % 10);
                tempN /= 10;
            }
            while (tempI != 0)
            {
                ms.insert(tempI % 10);
                tempI /= 10;
            }
            while (tempJ != 0)
            {
                ms.insert(tempJ % 10);
                tempJ /= 10;
            }
            if (ms.size() == 9 && ms.find(0) == ms.end())
            {
                bool pan = true;
                for (auto it = ms.begin(); it != ms.end(); it++)
                    if (ms.count(*it) != 1)
                        pan = false;
                if (!pan)
                    continue;
                return true;
            }
        }
    return false;
}