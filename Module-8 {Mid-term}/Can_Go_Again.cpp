#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const ll N = 1e5 + 5;
const ll INF = 1e18;
ll dis[N];
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    ll s, t;
    cin >> s >> t;
    dis[s] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    for (Edge ed : EdgeList)
    {
        ll u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            cout << "Negative Cycle Detected\n";
            return 0;
        }
    }
    while (t--)
    {
        ll d;
        cin >> d;
        if (dis[d] < INF)
            cout << dis[d] << endl;
        else
            cout << "Not Possible\n";
    }
    return 0;
}