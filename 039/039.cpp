// Problem 39 -- Integer right triangles
#include <iostream>
using namespace std;

unsigned int numPythagoreanTriples(unsigned int p);

int main()
{
    unsigned int maxP = 0;
    unsigned int max = 0;
    for (unsigned int i = 1; i <= 1000; i++)
    {
        unsigned int solutions = numPythagoreanTriples(i);
        if (solutions > max)
        {
            max = solutions;
            maxP = i;
        }
    }
    cout << maxP << "\n";
    return 0;
}

unsigned int numPythagoreanTriples(unsigned int p)
{
    unsigned int count = 0;
    for (unsigned int i = 1; i < p/2; i++)
        for (unsigned int j = i; j < p/2; j++)
            if (p - i - j > 0)
            {
                unsigned int hyp = p - i - j;
                if (hyp * hyp == i * i + j * j)
                    count++;
            }
    return count;
}