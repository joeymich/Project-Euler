// Problem 25 -- 1000-digit Fibonacci number
#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> add(vector<unsigned int>& v1, vector<unsigned int>& v2);

int main()
{
    vector<unsigned int> fib;
    vector<unsigned int> fib1 = {1};
    vector<unsigned int> fib2 = {1};
    unsigned int i = 2;
    while (fib.size() < 1000)
    {
        fib = add(fib1, fib2);
        fib2 = fib1;
        fib1 = fib;
        i++;
    }
    cout << i << "\n";
}

vector<unsigned int> add(vector<unsigned int>& v1, vector<unsigned int>& v2)
{
    vector<unsigned int> add = v1;
    unsigned int c = 0;
    for (unsigned int i = 0; i < add.size(); i++)
    {
        unsigned int temp;
        if (i < v2.size())
            temp = add.at(i) + v2.at(i) + c;
        else
            temp = add.at(i) + c;
        if (temp > 9)
        {
            add.at(i) = temp % 10;
            c = temp / 10;
        }
        else
        {
            add.at(i) = temp;
            c = 0;
        }
        if (i == add.size() - 1 && c != 0)
        {
            add.push_back(c);
            break;
        }
    }
    return add;
}