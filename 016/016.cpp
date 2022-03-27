// Problem 16 -- Power digit sum
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned int> digits = {1};
    for (unsigned int i = 1; i <= 1000; i++)
    {
        unsigned int carry = 0;
        for (unsigned int j = 0; j < digits.size(); j++)
        {
            unsigned int temp = digits.at(j) * 2 + carry;
            if (temp > 9)
            {
                digits.at(j) = temp % 10;
                carry = temp / 10;
                if (j == digits.size() - 1)
                {
                    digits.push_back(carry);
                    break;
                }
            }
            else
            {
                digits.at(j) = temp;
                carry = 0;
            }
        }
    }
    unsigned int sum_digits = 0;
    for (unsigned int i = 0; i < digits.size(); i++)
        sum_digits += digits.at(i);
    cout << sum_digits << "\n";
    return 0;
}