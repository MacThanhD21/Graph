#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))

const int N = 1005;

int n, m, timer = 1;
vector<int> adj[N];
int disc[1005], low[1005];
bool visited[1005];

bool AP[1001];

/* ALgo Tarjan :
- disc[i] : lưu lại thời gian bắt đầu đi thăm đỉnh i
  theo thuật toán DFS (Thời gian mở rộng đỉnh i)

- low[i] : lưu lại giá trị nhỏ nhất của mọi disc[j], trong đó j là tổ tiên
không phải cha trực tiếp của i

*/

/* aissss chet tiet */

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}

void dfsTru(int u, int par)
{
    low[u] = disc[u] = timer++;
    int counchild = 0;
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            ++counchild;
            dfsTru(v, u);
            // sau khi dfs trên chạy xong, cập nhật low[u]
            low[u] = min(low[u], low[v]);

            /* kiểm tra đỉnh trụ
             Điều kiện dưới có ý nghĩa là từ đỉnh v, sẽ không còn đường nào
             quay về cha của đỉnh u mà không thông qua đỉnh u
             Tức là đỉnh u sẽ làm con, muốn bước đến
            */

            if (low[v] >= disc[u] && par != -1)
            {
                // par != -1 nghĩa là u không phải đỉnh gốc
                AP[u] = true;
            }
        }
        // đỉnh v đã được thăm
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    // Trường hợp đỉnh đầu có 2 nhánh con thì nó cũng là đỉnh trụ
    if (par == -1 && counchild >= 2)
    {
        AP[u] = true;
    }
}

vector<pair<int, int>> bridge;

void dfsCau(int u, int par)
{
    low[u] = disc[u] = timer++;
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }
        if (disc[v] == 0)
        {
            dfsCau(v, u);
            // sau khi dfs trên chạy xong, cập nhật low[u]
            low[u] = min(low[u], low[v]);
            // kiểm tra canh cau
            // Nó không lấy dấu bằng vì
            // sẽ có trường hợp đỉnh u là đỉnh của 1 chu trình
            if (low[v] > disc[u])
            {
                bridge.pb({u, v});
            }
        }
        // đỉnh v đã được thăm
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    nhap();
    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == 0)
        {
            dfsCau(i, -1);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << disc[i] << " " << low[i] << "\n";
    // }
    // for(int u = 1; u <= n; u++){
    //     if(AP[u])
    //         cout << u << " ";
    // }
    sort(bridge.begin(), bridge.end());
    for (auto it : bridge)
    {
        cout << it.fi << " " << it.se << "\n";
    }
}