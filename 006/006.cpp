// Problem 6 -- Sum square difference
#include <iostream>
using namespace std;

int main()
{
    unsigned int sum = 0;
    unsigned int sumSquared = 0;
    unsigned  square;
    unsigned int sol;
    for (int i = 1; i < 101; i++) {
        sum += i;
        sumSquared += i * i;
    }
    square = sum * sum;
    sol = square - sumSquared;
    cout << sol << endl;
    return 0;
}