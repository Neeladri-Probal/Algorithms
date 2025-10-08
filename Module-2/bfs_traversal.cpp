#include<bits/stdc++.h>
using namespace std;
bool vis[1005];
vector<int> v[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for(auto child : v[par])
        {
            if(!vis[child])
            {
                q.push(child);
            vis[child] = 1;
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
    bfs(src);
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
//0 1 4 2 3