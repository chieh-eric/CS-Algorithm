#include <iostream>
#include <vector>
#include <limits.h>
#define SIZE 10000
#define NUM 100001
using namespace std;
struct task
{
    int d;
    int t;
    int w;
};
int compareD(const void *a, const void *b)
{
    task *p1 = (task *)a;
    task *p2 = (task *)b;
    return (p1->d - p2->d);
}
vector<int> S;
int m[SIZE][SIZE];
void schedule(task tk[], int m[][SIZE], int i, int j);
void dp(task tk[], int n)
{
    int index = 0;
    int work[n];
    qsort(tk, n + 1, sizeof(task), compareD);

    for (int i = 0; i <= n; i++)
    {
        m[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        m[0][i] = NUM;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i < j)
            {
                m[i][j] = NUM;
            }
            else
            {
                if (m[i - 1][j - 1] + tk[i].t <= tk[i].d)
                {
                    if (m[i - 1][j] > m[i - 1][j - 1] + tk[i].t)
                    {
                        m[i][j] = m[i - 1][j - 1] + tk[i].t;
                    }
                    else
                    {
                        m[i][j] = m[i - 1][j];
                    }
                }
                else
                {
                    m[i][j] = m[i - 1][j];
                }
            }
        }
    }
    int max_i;
    int temp = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        // cout << m[n][i] << " ";
        if (temp <= m[n][i] && m[n][i] != NUM)
        {
            temp = m[n][i];
            max_i = i;
        }
    }
    schedule(tk, m, n, max_i);
    for (int i = 0; i < S.size(); i++)
    {
        cout << S[i] << " ";
    }
}
void schedule(task tk[], int m[][SIZE], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (m[i - 1][j - 1] + tk[i].t <= tk[i].d)
    {
        if (m[i][j] == m[i - 1][j - 1] + tk[i].t)
        {
            schedule(tk, m, i - 1, j - 1);
            S.push_back(tk[i].w);
        }
        else
            schedule(tk, m, i - 1, j);
    }
    else
        schedule(tk, m, i - 1, j);
}
int main()
{
    int n;
    int work = 1;
    cin >> n;
    task tk[n + 1];
    tk[0].d = 0;
    tk[0].w = 0;
    tk[0].t = 0;
    vector<task> ans;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> tk[i].t >> tk[i].d;
        tk[i].w = work;
        work++;
    }
    dp(tk, n);
}