// Problem 22 -- Names scores
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    fstream ifs;
    ifs.open("names.txt");
    string line;
    getline(ifs, line);
    istringstream iss(line);
    string temp;
    vector<string> names;
    while(getline(iss, temp, ','))
    {
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        names.push_back(temp);
    }
    sort(names.begin(), names.end());
    unsigned int sum = 0;
    for (unsigned int i = 0; i < names.size(); i++)
    {
        unsigned int tempSum = 0;
        for (auto &ch : names[i])
            tempSum += ch - 'A' + 1;
        sum += tempSum * (i + 1);
    }
    cout << sum << "\n";
    return 0;
}