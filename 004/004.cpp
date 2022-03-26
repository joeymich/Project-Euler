// Problem 4 -- Largest palindrome product
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    unsigned int pal;
    vector<int> pals(0);
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            pal = i * j;
            string s = to_string(pal);
            bool palBool = true;
            while (s.length() > 1) {
                if (s.at(0) != s.at(s.length() - 1)) {
                    palBool = false;
                    break;
                }
                s = s.substr(1, s.length() - 2);
            }
            if (palBool) {
                pals.push_back(pal);
            }
        }
    }
    sort(pals.begin(), pals.end());
    cout << pals.back() << endl;
    return 0;
}