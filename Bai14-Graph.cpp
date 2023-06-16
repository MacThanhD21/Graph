#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

vector<int> a[1005]; // danh sach ke : O(V + E)
bool vs[1005];
int parent[1005];
vector<int> path;

void DFS(int u)
{
    vs[u] = true;
    for (int v : a[u])
    {
        if (!vs[v])
        {
            DFS(v);
            // Cap nhat dinh cha cua dinh v
            // Dinh u la cha dinh v
            parent[v] = u;
        }
    }
}

void run()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(a[i]));
    }

    DFS(s);
    // Neu dinh t chua duoc di tham => false
    if (vs[t] == false)
    {
        cout << "-1\n";
        return;
    }
    // Cap nhat duong di tu cuoi => 1
    else
    {
        while (s != t)
        {
            path.pb(t);
            t = parent[t];
        }
        // Them dinh s vao path
        path.pb(s);
        reverse(all(path));
        for (auto x : path)
        {
            cout << x << " ";
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

    run();
}