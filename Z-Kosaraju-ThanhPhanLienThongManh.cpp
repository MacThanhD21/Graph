#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
int n, m;
vector<int> adj[N], T_adj[N];
bool visited[N] = {false};
stack<int> st; // lưu thứ tự duyệt xong của các đỉnh
int check = 0;

// kosaraju  : áp dụng cho đồ thị có hướng

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        T_adj[y].pb(x); // đồ thị lật ngược
    }
}
// lấy thứ tự duyệt của các đỉnh khi chạy xong
void dfs_one(int u)
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            dfs_one(x);
        }
    }
    // đỉnh u đã chạy xong
    st.push(u);
}

// hàm này in ra các đỉnh kề với đỉnh u trong đồ thị ngược
void dfs_two(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (auto x : T_adj[u])
    {
        if (!visited[x])
        {
            dfs_two(x);
        }
    }
}

void Kosaraju()
{
    // B1 : lấy thứ tự các đỉnh trong đồ thị bằng hàm dfs_one;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs_one(i);
        }
    }
    memset(visited, false, sizeof(visited));
    // B2 : in ra các đỉnh trong mỗi thành phần liên thông mạnh
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            dfs_two(u);
            cout << "\n";
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    nhap();
    Kosaraju();
}