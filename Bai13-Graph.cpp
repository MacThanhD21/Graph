#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

// DFS : CAC ung dung
// 1. Kiem Tra Do Thi Co Lien Thong Hay khon
// 2. Dem So Luong Thanh Phan Lien Thong Cua Do Thi

vector<int> a[1005]; // danh sach ke : O(V + E)
bool vs[1005];
int G[1001][1001]; // ma tran ke : O(V^2)

void DFS(int u)
{
    vs[u] = true;
    for (int v : a[u])
    {
        if (!vs[v])
        {
            DFS(v);
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
    // duyet tu dinh 1 -> n
    for (int i = 1; i <= n; i++)
    {
        sort(all(a[i]));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i])
        {
            ++ans;
            DFS(i);
        }
    }
    cout << ans << "\n";
}