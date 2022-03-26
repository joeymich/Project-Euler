// Problem 5 -- Smallest multiple
#include <iostream>
using namespace std;

int main()
{
    bool solved = false;
    unsigned int i = 2520;
    while (!solved) {
        bool tempSolved = true;
        for (int j = 1; j < 21; j++) {
            if (!(i % j == 0)) {
                tempSolved = false;
                break;
            }
        }
        if (tempSolved == true) {
            solved = true;
        }
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}