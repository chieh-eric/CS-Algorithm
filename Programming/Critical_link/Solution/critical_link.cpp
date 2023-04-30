#include <bits/stdc++.h>
#define SIZE 100001
using namespace std;
int n, m;  
int num[SIZE], low[SIZE],previous[SIZE];
bool isbridge[SIZE],vis[SIZE];
int ct=0,ind ;
vector<int> edge[SIZE];       

void Tarjan(int u, int pre)
{
    vis[u] = true;
    previous[u] = pre;
    low[u] = num[u] = ++ct;          
    for (int v : edge[u])
    { 
        if(!num[v]) 
        {                  
            Tarjan(v, u);                 
            low[u] = min(low[u], low[v]); 
            if( low[v] > num[u])  
            {
                isbridge[v] = true;
            }
        } 
        else if(num[v] < num[u]&&v != pre)
            low[u] =min(low[u], num[v]);  
    }
}  
    

int main() {
    int x, y ,n;
    cin >> n ;                 
    while (cin >> x >> y)
    {  
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i = 0 ; i < n ; i++)
        if(!vis[i])
        {
            ind = 0;
            Tarjan(i,i);
        }
        
    for (int i = 1; i <= n; i++)
        if (isbridge[i]) cout << previous[i] << " " << i <<endl;  
  return 0;
}