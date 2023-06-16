#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, e;
    cin >> v >> e;
    pair<int, int> a[e];
    vector<int> G[1005];
    for (int i = 1; i <= e; i++)
    {
        cin >> a[i].first >> a[i].second;
        G[a[i].first].push_back(a[i].second);
        G[a[i].second].push_back(a[i].first);
    }
    for (int i = 1; i <= v; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << " : ";
        for (auto x : G[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}