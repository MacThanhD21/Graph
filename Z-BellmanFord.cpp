#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

struct edge
{
    int x, y, w;
};

int n, m, s;
vector<edge> adj;
int par[1005];

void init()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge tmp = {x, y, z};
        adj.pb(tmp);
    }
}

void BellmanFord(int s)
{
    int d[n + 1];
    fill(d + 1, d + n + 1, 1e9);

    d[s] = 0;
    par[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : adj)
        {
            int u = it.x, v = it.y, w = it.w;

            if (d[u] != 1e9 && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                par[v] = u;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " " << par[i] << "\n";
    }
}
int main()
{

    cin.tie(0)->sync_with_stdio(0);

    init();
    BellmanFord(s);
}