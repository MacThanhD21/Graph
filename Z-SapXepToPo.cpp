#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()

const int N = 1005;
vector<int> adj[N]; // danh sach ke : O(V + E)
bool vs[N] = {false};

int n, m;
int deg[1005]; // tính số bán bậc vào ở mỗi đỉnh

/* SapXepTopo : áp dụng cho đồ thị có hướng, không có chu trình (***) : BFS, DFS
Thu Tu Sap Xep topo nằm trên đồ thị
u -> v : đỉnh u luôn đứng trước v
- Điều kiện của TopoSort : nếu có cạnh nối u -> v, thì u phải dứng trước v
*/

/*
- ThuaToan Kahn_BFS() : dựa trên BFS : cũng duyệt thứ tự topo
Hay còn là: Xóa dần đỉnh
- Sử dụng Kiến thức về Bán Bậc Vào
- Sử dụng hàng đợi : Sẽ bỏ những đỉnh
có bán bậc vào bằng 0 vào hàng đợi
, nó sẽ là đỉnh đầu tiên Được in ra
ở mỗi thành phần liên thông khác nhau
- Sẽ cố gắng xóa dần đỉnh có bán bậc vào bằng 0
Để làm giảm bán bậc vào của các đỉnh khác(vì mất cạnh liên thông)
khi đó bán bậc vào của các đỉnh kề với đỉnh xóa sẽ giảm dần
cho đến khi bằng 0 lại tiếp tục đẩy vào
trong hàng đợi , exxxx...
*/

/* Ứng dụng kiểm tra chu trình trên đồ thị :
+ Có hướng : Nếu in ra tất cả các đỉnh trên đồ thị
   => không có chu trình
+ Vô hướng : Áp dụng lý thuyết cạnh ngược(back edge)
- Cạnh ngược : từ đỉnh CUỐI CÙNG có thể đến
đỉnh ông nội mà không cần đi qua đỉnh cha
của nó @@
*/

vector<int> topo;
void DFS(int u)
{
    vs[u] = true;
    for (auto x : adj[u])
    {
        if (!vs[x])
        {
            DFS(x);
        }
    }
    // dinh u duyet xong
    topo.pb(u);
}

void BFS_Kahn()
{
    queue<int> q;
    // Đưa những đỉnh có bán bậc vào
    // = 0 vào hàng đợi
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    // Duyệt khi hàng đợi còn chưa rỗng
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // Lấy đỉnh đầu tiên ra khỏi hàng đợi
        cout << u << " ";
        // duyệt các đỉnh kề
        // của đỉnh u
        for (auto v : adj[u])
        {
            --deg[v];
            if (deg[v] == 0)
            {
                q.push(v);
            }
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

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        deg[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
    }
    memset(vs, false, sizeof(vs));
    // for(int i = 1; <= n; i++){
    //     if(!vs[i]){
    //         DFS(i);
    //     }
    // }
    // reverse(topo.begin(), topo.end());
    // for(auto x : topo)
    //     cout << x << " ";
    BFS_Kahn();
}