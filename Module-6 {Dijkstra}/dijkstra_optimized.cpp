#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[100];
int dis[100];
class cmp
{
    public:
    bool operator()(pair<int,int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while(!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        for(auto child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 0; i < 100; i++)
        dis[i] = INT_MAX;
    dijkstra(0);
    for(int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;
}