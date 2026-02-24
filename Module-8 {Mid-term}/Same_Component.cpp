#include<bits/stdc++.h>
using namespace std;
char x[1003][1003];
int n, m;
bool vis[1003][1003];
vector<pair<int, int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0)
        return false;
    return true;
}
void bfs(int a,int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    vis[a][b] = true;
    while(!q.empty())
    {
        auto par = q.front();
        q.pop();
        auto si = par.first;
        auto sj = par.second;
        for(int i = 0 ; i < 4; i++)
        {
            auto ci = si + d[i].first; 
            auto cj = sj + d[i].second;
            if(valid(ci, cj) && x[ci][cj] != '-' && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j=0 ; j < m; j++)
        {
            cin >> x[i][j];
            vis[i][j] = 0;
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bfs(a, b);
    if(vis[c][d])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}