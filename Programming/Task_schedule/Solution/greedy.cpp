#include <iostream>
#include <queue>
#include <vector>
#define SIZE 10000
using namespace std;
struct task
{
    int d;
    int t;
    int w;
};
priority_queue<task> node;
task sol[SIZE];
struct CompareT
{
    bool operator()(task const &p1, task const &p2)
    {
        return p1.t < p2.t;
    }
};
int compareD(const void *a, const void *b)
{
    task *p1 = (task *)a;
    task *p2 = (task *)b;
    return (p1->d - p2->d);
}
vector<task> task_scheduling(task tk[], int n)
{
    int index = 0;
    int sum = 0;
    qsort(tk, n, sizeof(task), compareD);
    priority_queue<task, vector<task>, CompareT> S;
    for (int i = 0; i < n; i++)
    {
        S.push(tk[i]);
        sum += tk[i].t;
        if (sum > tk[i].d)
        {
            sum -= S.top().t;
            S.pop();
        }
    }
    while (!S.empty())
    {
        sol[index] = S.top();
        S.pop();
        index++;
    }
    vector<task> temp;
    for (int i = 0; i < index; i++)
    {
        temp.push_back(sol[i]);
    }
    for (int i = index - 1; i >= 0; i--)
    {
        cout << temp[i].w << " ";
    }
    return temp;
}
int main()
{
    int n;
    int work = 1;
    cin >> n;
    task tk[n];
    vector<task> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> tk[i].t >> tk[i].d;
        tk[i].w = work;
        work++;
    }
    ans = task_scheduling(tk, n);
}