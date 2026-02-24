#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[1003][1003];
int dis[1003][1003];
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
bool valid(int i, int j)
{
    return !(i >= n || i < 0 || j >= m || j < 0);
}
void bfs(int a, int b)
{
    dis[a][b] = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    vis[a][b] = true;
    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        auto si = par.first;
        auto sj = par.second;
        for (int i = 0; i < 8; i++)
        {
            auto ci = si + d[i].first;
            auto cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = 1;
                dis[ci][cj] = dis[si][sj] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                vis[i][j] = 0;
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bfs(a, b);
        if (vis[c][d])
            cout << dis[c][d] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}