#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child : v[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    int src, des;
    cin >> src >> des;
    bfs(src);
    while(des!=-1)
    {
        cout << des << " ";
        des = parent[des];
    }
}

//input
// 6 7
// 0 1
// 1 2
// 1 3
// 2 4
// 2 5
// 4 5 
// 4 3
// 0 5

//output
//5 2 1 0