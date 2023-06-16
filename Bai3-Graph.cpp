#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> G[1005];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        // G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto x : G[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}