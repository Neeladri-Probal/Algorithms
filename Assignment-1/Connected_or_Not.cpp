#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000000];
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int t, src, des;
    cin >> t;
    while(t--)
    {
        bool flag = true;
        cin >> src >> des;
        if(src == des)
        {
            cout << "YES\n";
            continue;
        }
        for(int child : v[src])
        {
            if(child == des)
            {
                printf("YES\n");
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "NO\n";
    }
}