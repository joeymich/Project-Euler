// Problem 52 -- Permutated multiples
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutation(unsigned int n1, unsigned int n2);

int main()
{
    int num = 125875;
    while(1)
    {
        for (int i = 2; i < 7; i++)
        {
            if (isPermutation(num, num*i))
            {
                if (i == 6)
                    goto end;
                continue;
            }
            else
                break;
        }
        num++;
    }
    end:
        cout << num << "\n";
    return 0;
}

bool isPermutation(unsigned int n1, unsigned int n2)
{
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    return is_permutation(s1.begin(), s1.end(), s2.begin());
}