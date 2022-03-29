// Problem 18 -- Maximum path sum I
#include <iostream>
#include <vector>
using namespace std;

/*
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/

struct Node
{
    unsigned int val;
    unsigned int runningMax;
};

int main()
{
    vector<Node> nodes;
    for (unsigned int i = 0; i < 15; i++)
    {
        vector<Node> tempNodes;
        for (unsigned int j = 0; j < i + 1; j++)
        {
            Node temp;
            cin >> temp.val;
            unsigned int parent1 = 0;
            unsigned int parent2 = 0;
            if (i != 0)
            {
                    unsigned int index = j;
                if (j == 0)
                    parent1 = nodes[index].runningMax;
                else if (j == i)
                    parent1 = nodes[index - 1].runningMax;
                else
                {
                    parent1 = nodes[index - 1].runningMax;
                    parent2 = nodes[index].runningMax;
                }
            }
            if (parent1 > parent2)
                temp.runningMax = parent1 + temp.val;
            else
                temp.runningMax = parent2 + temp.val;
            tempNodes.push_back(temp);
        }
        nodes = tempNodes;
    }
    unsigned int max = nodes[0].runningMax;
    for (unsigned int i = 0; i < nodes.size(); i++)
        if (nodes.at(i).runningMax > max)
            max = nodes.at(i).runningMax;
    cout << max << "\n";
    return 0;
}