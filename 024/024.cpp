// Problem 24 -- Lexicogaphic permutations
#include <iostream>
#include <vector>
using namespace std;

int fact(int n);

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int rem = 1000000 - 1;
    int perm[10];
    for (size_t i = 0; i < 10; i++)
    {
        int j = rem/fact(9 - i);
        perm[i] = nums[j];
        nums.erase(nums.begin() + j);
        rem %= fact(9 - i);
    }
    for (size_t i = 0; i < 10; i++)
        cout << perm[i];
    return 0;
}

int fact(int n)
{
    int temp = 1;
    for (size_t i = 2; i <= n; i++)
        temp *= i;
    return temp;
}