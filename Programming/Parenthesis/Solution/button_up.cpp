#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

bool isOperator(char op)
{

    return (op == '+' || op == '*' || op == '-');
}
long long int find_min(long long int a, long long int b, long long int c, long long int d)
{
    long long int m = LLONG_MAX;
    m = min(a, b);
    m = min(m, c);
    m = min(m, d);
    return m;
}
long long int find_max(long long int a, long long int b, long long int c, long long int d)
{
    long long int m = LLONG_MIN;
    m = max(a, b);
    m = max(m, c);
    m = max(m, d);
    return m;
}
// string paranthesis(string op,long long int a,long long int b,long long int c,long long int d,long long int ans,long long int** min,long long int** max)
// {
//     char* str=op;
//     switch(str))
//     {
//         case
//     }

// }
void printMinAndMaxValueOfExp(string exp)
{
    vector<long long int> num;
    vector<char> opr;
    string tmp = "";
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            opr.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += exp[i];
        }
    }
    num.push_back(atoi(tmp.c_str()));
    long long int len = num.size();
    long long int minVal[len][len];
    long long int maxVal[len][len];
    string minExp[len][len];
    string maxExp[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {

            minVal[i][j] = LLONG_MAX;
            maxVal[i][j] = LLONG_MIN;
            if (i == j)
            {
                minExp[i][j] = to_string(num[i]);
                maxExp[i][j] = to_string(num[i]);
                minVal[i][j] = maxVal[i][j] = num[i];
            }
        }
    }
    for (int L = 2; L <= len; L++)
    {
        for (int i = 0; i < len - L + 1; i++)
        {
            int j = i + L - 1;
            for (int k = i; k < j; k++)
            {
                long long int minTmp, maxTmp;
                long long int a, b, c, d;
                string op = "", min_expTmp = "", max_expTmp = "";
                if (opr[k] == '+')
                {
                    a = minVal[i][k] + maxVal[k + 1][j];
                    b = maxVal[i][k] + minVal[k + 1][j];
                    c = minVal[i][k] + minVal[k + 1][j];
                    d = maxVal[i][k] + maxVal[k + 1][j];
                    minTmp = find_min(a, b, c, d);
                    maxTmp = find_max(a, b, c, d);
                    op = "+";
                    if (minTmp == a)
                        min_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (minTmp == b)
                        min_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == c)
                        min_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == d)
                        min_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";

                    if (maxTmp == a)
                        max_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (maxTmp == b)
                        max_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == c)
                        max_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == d)
                        max_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";
                }
                else if (opr[k] == '*')
                {
                    a = minVal[i][k] * maxVal[k + 1][j];
                    b = maxVal[i][k] * minVal[k + 1][j];
                    c = minVal[i][k] * minVal[k + 1][j];
                    d = maxVal[i][k] * maxVal[k + 1][j];
                    minTmp = find_min(a, b, c, d);
                    maxTmp = find_max(a, b, c, d);
                    op = "*";
                    if (minTmp == a)
                        min_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (minTmp == b)
                        min_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == c)
                        min_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == d)
                        min_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";

                    if (maxTmp == a)
                        max_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (maxTmp == b)
                        max_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == c)
                        max_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == d)
                        max_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";
                }
                else if (opr[k] == '-')
                {
                    a = minVal[i][k] - maxVal[k + 1][j];
                    b = maxVal[i][k] - minVal[k + 1][j];
                    c = minVal[i][k] - minVal[k + 1][j];
                    d = maxVal[i][k] - maxVal[k + 1][j];
                    minTmp = find_min(a, b, c, d);
                    maxTmp = find_max(a, b, c, d);
                    op = "-";
                    if (minTmp == a)
                        min_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (minTmp == b)
                        min_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == c)
                        min_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (minTmp == d)
                        min_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";

                    if (maxTmp == a)
                        max_expTmp = "(" + minExp[i][k] + op + maxExp[k + 1][j] + ")";
                    if (maxTmp == b)
                        max_expTmp = "(" + maxExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == c)
                        max_expTmp = "(" + minExp[i][k] + op + minExp[k + 1][j] + ")";
                    if (maxTmp == d)
                        max_expTmp = "(" + maxExp[i][k] + op + maxExp[k + 1][j] + ")";
                }
                if (minTmp < minVal[i][j])
                {
                    minVal[i][j] = minTmp;
                    minExp[i][j] = min_expTmp;
                    min_expTmp = "";
                }

                if (maxTmp > maxVal[i][j])
                {
                    maxVal[i][j] = maxTmp;
                    maxExp[i][j] = max_expTmp;
                    max_expTmp = "";
                }
            }
        }
    }
    maxExp[0][len - 1].pop_back();
    maxExp[0][len - 1].erase(0, 1);
    cout << maxVal[0][len - 1]
         << endl
         << maxExp[0][len - 1] << endl;
}

int main()
{
    string expression;
    cin >> expression;

    printMinAndMaxValueOfExp(expression);

    return 0;
}