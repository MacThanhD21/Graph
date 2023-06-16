#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

/* DIJKSTRA : Áp dụng bài toán tìm đường đi ngắn nhất
từ 1 đỉnh bất kỳ đến tất cả các đỉnh còn lại

- Không áp dụng cho đồ thị có cạnh âm

 - Tạo 1 mảng d[i] : lưu đường đi ngắn nhất từ đỉnh s -> i
 - Tạo 1 hàng đợi ưu tiên lưu pair<kc, đỉnh>
  + Tất cả các đỉnh khởi tạo bằng vô cùng trừ đỉnh gốc
  + Đẩy ({0, s}) vào trong hàng đợi

  + Xử lý trường hợp Nếu khoảng cách hiện tại của nó > khoảng cách đã xét
    trước đó thì sẽ pop đỉnh đó đi
  + Kiểm tra điều kiện : d[v] > d[u] + w;
  (trong đó : v là đỉnh kề với đỉnh u, w là trọng số đi kèm
   + d[v] : là khoảng cách từ đỉnh s -> v, d[u] tương tự
  )
*/

int n, m;
vector<ii> adj[10005];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].pb({y, z});
    }
}

void DiJKSTRA(int s)
{
    int d[n + 1]; // d[i] : lưu lại khoảng cách ngắn nhất từ đỉnh s -> đỉnh i
    // Sẽ đánh dấu khoảng cách tại đỉnh s là 0 và tất cả các đỉnh
    // còn lại có khoảng cách là vô cùng(1e9)
    fill(d + 1, d + n, 1e9);
    d[s] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, s});

    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        /*
        - Lấy ra khoảng cách hiện tại và đỉnh hiện tại để xét
        */
        int disTance = top.first, u = top.second;
        /*
        - Điều kiện if này có nghĩa là trong hàng đợi nó đã có phiên bản tốt hơn
        (đường đi tốt hơn) rồi nên continue
        */
        if (disTance > d[u])
            continue;
        for (auto it : adj[u])
        {
            int v = it.first, w = it.second;
            // kiểm tra đường đi từ s -> v có > từ s -> u + (u -> v) không ?

            /*
            - kiểm tra xem khoảng cách từ s -> v có lớn hơn khoảng cách từ (s -> u) + (u -> v) hay không
            */

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    DiJKSTRA(1);
}