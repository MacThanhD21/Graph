#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N]; // danh sach ke : O(V + E)
bool vs[N] = {false};
vector<pair<int, int>> edge;

// Ly Thuyet Canh Cau :
//- Khi bỏ 1 cạnh bất kỳ sẽ làm tăng số lượng thành phần liên thông

// -Idea : loại bỏ thử các cạnh cầu (không bỏ đỉnh)
// xem là có tăng số thành phần liên thông hay không

void DFS(int u, int s, int t)
{ // Thử loại bỏ cạnh [st] ra khỏi đồ thị
  // xem có làm tăng thành phần liên thông hay không
    vs[u] = true;
    // Duyet cac dinh ke voi dinh u
    for (int v : adj[u])
    {
        if ((u == s && v == t) || (u == t && v == s))
        {
            continue;
        }
        if (!vs[v])
            DFS(v, s, t);
    }
}

void run()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        edge.push_back({x, y});
    }

    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }

    int cnt = 0; // số thành phần liên thông ban đầu
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i])
        {
            ++cnt;
            DFS(i, 0, 0);
        }
    }
    // cout << cnt << "\n";
    int ans = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        memset(vs, false, sizeof(vs));
        int coun = 0;
        // 2 đỉnh thử loại bỏ
        int s = edge[i].fi;
        int t = edge[i].se;
        for (int j = 1; j <= n; j++)
        {
            if (!vs[j])
            {
                ++coun;
                DFS(j, s, t);
            }
        }
        // cout << coun << "\n";
        if (coun > cnt)
            ++ans;
    }
    cout << ans << "\n";
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