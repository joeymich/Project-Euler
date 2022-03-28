// Problem 17 -- Number letter counts
#include <iostream>
#include <vector>
using namespace std;

string numToString(unsigned int num, vector<string> &words)
{
    if (num > 0 && num < 20)
        return words.at(num - 1);
    else if (num >= 20 && num < 100)
        return words.at(num / 10 + 17) + (num % 10 != 0 ? words.at(num % 10 - 1) : "");
    else if (num >= 100 && num < 1000)
        return words.at(num / 100 - 1) + "hundred" + (num % 100 != 0 ? "and" + numToString(num % 100, words) : "");
    else
        return "onethousand";
}

int main()
{
    vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= 1000; i++)
        sum += numToString(i, words).length();
    cout << sum << "\n";
    return 0;
}