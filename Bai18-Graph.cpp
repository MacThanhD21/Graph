#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

vector<int> a[1005]; // danh sach ke : O(V + E)
bool vs[1005];
int Coun[1005]; // Dem thanh phan lien thong
int cnt;

void BFS(int u)
{
    Coun[u] = cnt;
    queue<int> Q;
    Q.push(u);
    vs[u] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : a[u])
        {
            if (!vs[v])
            {
                Q.push(v);
                vs[v] = true;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    int q;
    cin >> q;

    for (int i = 1; i <= n; i++)
    {
        sort(all(a[i]));
    }
    for (int u = 1; u <= n; u++)
    {
        if (!vs[u])
        {
            ++cnt;
            BFS(u);
        }
    }

    while (q--)
    {
        int s, t;
        cin >> s >> t;
        if (Coun[s] == Coun[t])
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}