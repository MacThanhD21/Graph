#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int G1[n + 1][n + 1];
    int G2[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> G1[i][j];
            G2[i][j] = G1[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (G1[i][j])
            {
                cout << j << " " << i << "\n";
                G1[j][i] = 0;
            }
        }
    }

    cout << "\n";

    vector<int> adj[1005];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (G2[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}