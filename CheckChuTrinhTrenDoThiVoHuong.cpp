#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

/* Để kiểm tra chu trình
trên đồ thị vô hướng , ta dùng lý thuyết về cạnh ngược

- Cạnh ngược : từ đỉnh CUỐI CÙNG có thể đến
đỉnh ông nội mà không cần đi qua đỉnh cha
của nó @@
*/

int parent[1005];
bool visited[1005];
vector<int> adj[1005];

bool DFS(int u)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            if (DFS(x))
                return true;
            parent[x] = u;
        }
        else if (v != parent[u])
            return true;
    }
    return false;
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
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (DFS(i))
            {
                cout << "1\n";
                return;
            }
        }
    }
    cout << "0\n";
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