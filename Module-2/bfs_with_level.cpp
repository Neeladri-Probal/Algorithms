#include<bits/stdc++.h>
using namespace std;
bool vis[1005];
vector<int> v[1005];
int level[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    level[src] = 0;
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
                level[child] = level[par] + 1;
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
    int src;
    cin >> src;
    memset(vis, -1, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(src);
    for(int i=0;i<n;i++)
    {
        cout << i << " " << level[i] << endl;
    }
    return 0;
}
// Input
// 5 6
// 0 1
// 1 2
// 0 4
// 1 3
// 2 0
// 3 4
// 0  

//Output
//0 0
// 1 1
// 2 1
// 3 2
// 4 1
