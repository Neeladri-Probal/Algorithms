#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find_leader(int node)
{
    if(parent[node]==-1) return node;
    return parent[node] = find_leader(parent[node]);
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = find_leader(node1);
    int leaderB = find_leader(node2);
    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    int n, e;
    cin >> n >> e; 
    dsu_initialize(n);
    bool cycle = 0;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        if(find_leader(a) == find_leader(b))
            cycle = 1;
        else    
            dsu_union_by_size(a, b);
    }
    if(cycle)
        cout << "Cycle detected";
    else 
        cout << "Cycle not found";
    return 0;
}