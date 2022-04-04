// Problem 28 -- Number spiral diagonals
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned int sum = 1;
    for (unsigned int i = 0; i < 500; i++)
        sum += 4 * (i * 2 + 3) * (i * 2 + 3) - 12 * (i + 1);
    cout << sum;
    return 0;
}