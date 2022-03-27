// Problem 15 -- Lattice paths
#include <iostream>
#include <vector>
using namespace std;

unsigned long long binomial(unsigned int a, unsigned int b)
{
    unsigned long long answer = 1;
    for (unsigned int i = b + 1; i <= a; i++)
    {
        answer *= i;
        answer /= (i - b);
    }
    return answer;
}

int main()
{
    cout << binomial(40, 20) << "\n";
    return 0;
}