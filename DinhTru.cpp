#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N]; // danh sach ke : O(V + E)
bool vs[N] = {false};

// Ly Thuyet Dinh Tru :
// - Khi bỏ DINH TRU đó và các cạnh
// liên thuộc với đỉnh đó , nó sẽ làm tăng
// các thành phần liên thông.

void DFS(int u)
{
    vs[u] = true;
    // Duyet cac dinh ke voi dinh u
    for (int v : adj[u])
    {
        if (!vs[v])
        {
            DFS(v);
        }
    }
}

void run()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int cnt = 0;
    // Đếm số thành phần liên thông ban đầu
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i])
        {
            ++cnt; // Tăng thêm 1 thành phần liên thông
            DFS(i);
        }
    }
    // Đếm lại số thành phần liên thông mỗi đỉnh
    // Nếu lớn hơn số thành phần liên thông ban đầu
    // Sẽ có thêm 1 đỉnh trụ

    int ans = 0; // Số Đỉnh Trụ

    for (int i = 1; i <= n; i++)
    {
        memset(vs, false, sizeof(vs));
        vs[i] = true; // Bỏ tạm thời đỉnh i xem
        // có tăng thành phần liên thông hay không
        int coun = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vs[j])
            {
                ++coun;
                DFS(j);
            }
        }
        // cout << coun << " ";
        if (coun > cnt)
        {
            ++ans;
        }
    }
    cout << ans << "\n";
    // cout << cnt << "\n";
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