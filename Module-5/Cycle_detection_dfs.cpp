#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 
vector<int> adj[N];
bool vis[N];
bool cycle;
int parentArray[N];
void dfs(int par)
{
    vis[par] = 1;
    for(auto child : adj[par])
    {
        if(vis[child] && parentArray[par] != child)
        {
            cycle = 1;
        }
        if(!vis[child])
        {
            parentArray[child] = par;
            dfs(child);
        }
    }
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
        adj[b].push_back(a); 
    }
    memset(vis,false,sizeof(vis));
    memset(parentArray,-1,sizeof(parentArray));
    cycle = false;
    int src;
    cin >> src;
    dfs(src);
    if(cycle)
        cout << "cycle ase";
    else 
        cout << "cycle nai";
}