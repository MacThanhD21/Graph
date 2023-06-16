#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))

const int N = 1005;

/* KrusKal : chỉ áp dụng cho đồ thị vô hướng có trọng số

 - Khái niệm Cây : không có chu trình

 - Bài toán : Tìm cây khung mà nó có tổng các trọng số
 trên các cây khung đó là nhỏ nhất

 - Dùng hàm Union trong DSU để check xem khi đưa 1 cạnh vào cây khung có tạo thành
 chu trình hay ko?

 - Khi mà độ dài cây khung bằng n - 1 cạnh tức là đã duyệt tất cả các cạnh
 trong đồ thị thì dừng

 - Các bước giải quyết bài toán :
   + Sort danh sách cạnh theo thứ tự tăng dần về trọng số
   + lần lượt lấy ra 2 đỉnh để ghép vào khung
   + Nếu 2 đỉnh nối với nhau mà tạo thành chu trình thì loại
   + Nếu số lượng cạnh trong MST(minimum spanning tree : cây khung cực tiểu)
    == n - 1 thì break;
   + Còn không thì cập nhật đỉnh , cạnh và trọng số vào khung

*/

struct edge
{
    int u, v, w;
};

vector<edge> adj;

int n, m;
int parent[1005], sz[1005];

// Khoi tao
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj.pb({x, y, w});
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
// DSU
int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return false;
    if (sz[x] <= sz[y])
    {
        parent[x] = y;
        sz[x] += sz[y];
    }
    else
    {
        sz[y] += sz[x];
        parent[y] = x;
    }
    return true;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void Kruskal()
{
    int ans = 0; // Cây khung có tổng trọng số nhỏ nhất
    vector<edge> MST;
    sort(begin(adj), end(adj), cmp);
    for (int i = 0; i < adj.size(); i++)
    {
        // Nếu MST.size() == n - 1 thì break , tức là đã xây dựng được cây
        // khung kết nối với tất cả các đỉnh của đồ thị, có n - 1 cạnh
        if (MST.size() == n - 1)
            break;
        int x = adj[i].u, y = adj[i].v, z = adj[i].w;
        if (Union(x, y))
        {
            ans += z;
            MST.pb(adj[i]);
        }
    }
    // Nếu MST.size() != n - 1 thì đồ thị KHÔNG liên thông
    cout << ans << "\n";
    for (auto it : MST)
    {
        cout << it.u << " " << it.v << " " << it.w << "\n";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init();
    Kruskal();
}