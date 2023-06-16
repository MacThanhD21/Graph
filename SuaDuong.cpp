#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))
#define ll long long

#define ii pair<int, int>
int n, m;
vector<ii> adj[100005];
bool visited[100005];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(visited, false, sizeof(visited));
}

void prim(int s)
{
    ll d = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q; // min_heap
    Q.push({0, s});
    int cnt = 0;
    // visited[s] = true;
    while (!Q.empty())
    {
        // lấy ra cặp ở đỉnh hàng đợi
        pair<int, int> top = Q.top();
        Q.pop();
        // top.first : trọng số
        // top.second : đỉnh nào đó trong đồ thị
        if (visited[top.second])
            continue;
        d += top.first;
        ++cnt;
        visited[top.second] = true;
        // duyệt danh sách kề của thằng top.second
        for (auto it : adj[top.second])
        {
            // it.first : đỉnh kề với top.second
            // it.second : trọng số giữa 2 đỉnh đó
            if (!visited[it.first])
                Q.push({it.second, it.first});
        }
    }
    // nếu cnt != n thì không liên thông, prim không duyệt hết tất cả các đỉnh
    if (cnt != n)
        cout << "IMPOSSIBLE\n";
    else
        cout << d << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init();
    prim(1);
}