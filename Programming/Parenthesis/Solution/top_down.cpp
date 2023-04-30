#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;
bool isOperator(char op)
{
    return (op == '+' || op == '*' || op == '-');
}
int apply(int m, char op, int n)
{
    if (op == '+')
        return m + n;
    if (op == '-')
        return m - n;
    if (op == '*')
        return m * n;
}
string find_operators(string exp)
{
    string opr;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            opr.push_back(exp[i]);
        }
    }
    return opr;
}
int topdown(string exp)
{
    string oprs = find_operators(exp);
    if (oprs.size()==0)
        return exp[0];
}