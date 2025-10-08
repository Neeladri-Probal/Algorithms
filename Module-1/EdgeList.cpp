#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> v;
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(auto p : v)
        cout << p.first << " " << p.second << endl;
}

// Input
// 6 6
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10
// 11 12

// Output
// 1 2
// 3 4
// 5 6
// 7 8
// 9 10
// 11 12