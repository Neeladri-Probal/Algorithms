#include<bits/stdc++.h>
using namespace std;
vector<int> v[100000];
bool vis[100000];
void dfs(int src)
{
    cout << src << endl;
    vis[src] = 1;
    for(auto child : v[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    int src;
    cin >> src;
    dfs(src);
}