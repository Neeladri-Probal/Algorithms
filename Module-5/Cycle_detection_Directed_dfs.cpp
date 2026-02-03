#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 
vector<int> adj[N];
bool vis[N];
bool cycle;
bool path[N];
void dfs(int par)
{
    vis[par] = 1;
    path[par] = 1;
    for(auto child : adj[par])
    {
        if(path[child])
        {
            cycle = 1;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    path[par] = 0;
}
int main()
{
    int n,e; 
    cin >> n >> e;
    while(e--)
    {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b); 
    }
    memset(vis,false,sizeof(vis));
    memset(path,false,sizeof(path));
    cycle = false;
    int src;
    cin >> src;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(cycle)
        cout << "cycle ase";
    else 
        cout << "cycle nai";
}