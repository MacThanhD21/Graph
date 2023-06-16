#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

// BFS : CAC ung dung
// 1. Kiem Tra Do Thi Co Lien Thong Hay khon
// 2. Dem So Luong Thanh Phan Lien Thong Cua Do Thi

vector<int> a[1005]; // danh sach ke : O(V + E)
bool vs[1005];
int parent[1005];

void BFS(int u)
{
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
                parent[v] = u;
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
    BFS(s);
    if (vs[t] == false)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        vector<int> path;
        while (s != t)
        {
            path.pb(t);
            t = parent[t];
        }
        path.pb(s);
        reverse(all(path));
        for (auto x : path)
        {
            cout << x << " ";
        }
    }
}