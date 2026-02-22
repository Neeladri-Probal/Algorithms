#include <bits/stdc++.h>
using namespace std;
int dis[105];
vector<pair<int, int>> v[1000];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while(!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        for(auto child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                q.push({childNode,dis[childNode]});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 105; i++)
        dis[i] = INT_MAX;
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        
    }
    dijkstra(s);
    cout << dis[f];
}