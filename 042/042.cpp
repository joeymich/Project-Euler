// Problem 42 -- Coded triangle numbers
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool isTriangleNum(unsigned int n);
void loadWords(vector<unsigned int>& v);

int main()
{
    vector<unsigned int> words;
    loadWords(words);
    unsigned int count = count_if(words.begin(), words.end(), [](unsigned int i){return isTriangleNum(i);});
    cout << count << "\n";
    return 0;
}

bool isTriangleNum(unsigned int n)
{
    unsigned int i = 1;
    unsigned int temp = 0;
    do
    {
        temp = i * (i + 1) / 2;
        if (temp == n)
            return true;
        i++;
    } while (temp < 193);
    return false;
}

void loadWords(vector<unsigned int>& v)
{
    fstream ifs;
    ifs.open("words.txt");
    string line;
    getline(ifs, line);
    istringstream iss(line);
    string temp;
    while(getline(iss, temp, ','))
    {
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        unsigned int tempSum = 0;
        for (auto &ch : temp)
            tempSum += ch - 'A' + 1;
        v.push_back(tempSum);
    }
}