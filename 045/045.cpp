// Problem 45 -- Triangular, pentagonal, and hexagonal
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int triangle(unsigned int n);
unsigned int pentagonal(unsigned int n);
unsigned int hexagonal(unsigned int n);

int main()
{
    unsigned int n1 = 286;
    unsigned int n2 = 166;
    unsigned int n3 = 144;
    unsigned int minimum;
    while (1)
    {
        unsigned int tri = triangle(n1);
        unsigned int pen = pentagonal(n2);
        unsigned int hex = hexagonal(n3);
        minimum = min(min(tri, pen), hex);
        if (minimum == tri && minimum == pen && minimum == hex)
            break;
        if (minimum == tri)
            n1++;
        if (minimum == pen)
            n2++;
        if (minimum == hex)
            n3++;
    }
    cout << minimum << "\n";
    return 0;
}

unsigned int triangle(unsigned int n)
{
    return n * (n + 1) / 2;
}

unsigned int pentagonal(unsigned int n)
{
    return n * (3 * n - 1) / 2;
}

unsigned int hexagonal(unsigned int n)
{
    return n * (2 * n - 1);
}