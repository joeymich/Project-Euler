// Problem 9 -- Special Pythagorean triplet
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long answer = 0;
    for (unsigned int a = 1; a < 1000; a++) {
        bool found = false;
        for (unsigned int b = 1; b < 1000; b++) {
            unsigned int temp = a * a + b * b;
            unsigned int c = sqrt(temp);
            unsigned int product = a * b * c;
            if (c * c == temp && a + b + c == 1000) {
                found = true;
                answer = product;
                break;
            }
        }
        if (found)
            break;
    }
    cout << answer << endl;
    return 0;
}