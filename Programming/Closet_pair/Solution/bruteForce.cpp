#include <iostream>
#include <math.h>
#include "bruteForce.h"

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
float bruteForce(Point p[], int size)
{
    int min_val = 100001;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (dist(p[i], p[j]) < min_val)
            {
                min_val = dist(p[i], p[j]);
            }
        }
    }
    return min_val;
}
// int main()
// {
//     p[0].x = 2;
//     p[0].y = 3;
//     p[1].x = -10;
//     p[1].y = 5;
//     bruteForce(p, 2);
// }