// Problem 14 -- Longest Collatz sequence
#include <iostream>
using namespace std;

int collatz_length(unsigned int start)
{
    unsigned int length = 1;
    unsigned long long term = start;
    while (term != 1) {
        if (term % 2 == 0) {
            term /= 2;
            length++;
        }
        else {
            term *= 3;
            term += 1;
            length++;
        }
    }
    return length;
}

int main()
{
    unsigned int max = 0;
    unsigned int solution;
    for (unsigned int i = 1; i < 1000000; i++) {
        if (i % 2 == 0)
            continue;
        unsigned int length = collatz_length(i);
        if (length > max) {
            max = length;
            solution = i;
        }
    }
    cout << solution << "\n";
    return 0;
}