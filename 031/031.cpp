// Problem 31 -- Coin sums
#include <iostream>
#include <vector>
using namespace std;

unsigned int combinationCount(int amount, vector<unsigned int>& count, size_t i);

int main()
{
    vector<unsigned int> coins = {200, 100, 50, 20, 10, 5, 2, 1};
    unsigned int combinations = combinationCount(200, coins, 0);
    cout << combinations << "\n";
    return 0;
}

unsigned int combinationCount(int amount, vector<unsigned int>& coins, size_t i)
{
    if (amount == 0)
        return 1;
    else if (amount < 0 || coins.size() == i)
        return 0;
    else
    {
        unsigned int count1 = combinationCount(amount - coins[i], coins, i);
        unsigned int count2 = combinationCount(amount, coins, i + 1);
        return count1 + count2;
    }
}