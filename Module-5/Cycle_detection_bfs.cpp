#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 
vector<int> adj[N];
bool vis[N];
bool cycle;
int parentArray[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child : adj[par])
        {
            if(vis[child] && parentArray[par] != child)
            {
                cycle = 1;
            }
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                parentArray[child] = par;
            }
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
    bfs(src);
    if(cycle)
        cout << "cycle ase";
    else 
        cout << "cycle nai";
}