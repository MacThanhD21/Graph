#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))
#define ll long long

const int N = 1005;

/*
- Prim : tư tưởng :
 Cách 1 : duyệt trâu
 + Ta sẽ có 2 tập : V và VH
  - Tập V sẽ lưu các đỉnh (đánh dấu là false)
  - Tập VH sẽ lưu các đỉnh đã duyệt(đánh dấu là true)
 Cách 2 : dùng hàng đợi ưu tiên
 (slide)
*/

// struct edge{
//     int x, y, w;
// };

// int n, m, parert[100001], sz[100001];
// vector<pair<int, int>> adj[100005];
// bool visited[100001];

/* Cách 1 : Duyệt trâu
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj.push_back({x, y, w});
    }
    memset(visited, false, sizeof(visited));
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(visited[i] == false)
            return false;
    }
    return true;
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void prim(int s){
    ll d = 0, cnt = 0;
    visited[s] = true; // đưa đỉnh đầu tiên vào tâp VH
    sort(adj.begin(), adj.end(), cmp);
    while(!check()){
        // tìm cạnh ngắn nhất
        for(int i = 0; i < m; i++){
            int x = adj[i].x, y = adj[i].y, w = adj[i].w;
            // lúc này đỉnh s -> x or s -> y đã là ngắn nhất
            // chỉ cần kiểm tra nó đã được thăm hay chưa
            if(visited[x] != visited[y]){
                d += w;
                ++cnt;
                visited[x] = visited[y] = true;
                break;
            }
        }
    }
    if(cnt != n - 1)
        cout << "IMPOSSIBLE\n";
    else
        cout << d << "\n";
}
*/

// Cách 2: dùng priority_queue

#define ii pair<int, int>
int n, m;
vector<ii> adj[100005];
bool visited[100005];

vector<ii> T;
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
    int cnt = 0; // đếm số đỉnh của đồ thị
    visited[s] = true;
    while (!Q.empty())
    {
        // lấy ra cặp ở đỉnh hàng đợi
        pair<int, int> top = Q.top();
        Q.pop();
        // top.first : trọng số
        // top.second : đỉnh nào đó trong đồ thị

        // bỏ qua các đỉnh đã có nhiều phiên bản trong hàng đợi
        // ví dụ {1, 2} , {3, 2} thì 1,2 đã duyệt rồi và có trọng số nhỏ nhất,
        // nên 3, 2 không cần xét nữa

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
    // nếu cnt != n thì không liên thông,
    // tức là prim không duyệt hết tất cả các đỉnh
    if (cnt != n)
        cout << "IMPOSSIBLE\n";
    else
        cout << d << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    prim(1);
}

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))
#define ll long long

#define MAX 100
int n, m, a[MAX][MAX];           // Ma trận trọng số
vector<pair<int, int>> adj[MAX]; // Danh sách kề được chuyển đổi từ ma trận trọng số
bool visited[MAX];               // Mảng đánh dấu các đỉnh

// Hàm chuyển đổi từ ma trận trọng số sang danh sách kề
void khoitao()
{
    cin >> n >> m;

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= m; v++)
        {
            cin >> a[u][v];
            ` if (a[u][v] != 0)
            {
                adj[u].push_back({v, a[u][v]});
                adj[v].push_back({u, a[u][v]});
            }
        }
    }
}

void PRIM(int s)
{
    long long d = 0;
    // Hàng đợi ưu tiên luôn lưu trọng số nhỏ nhất ở đầu
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    int cnt = 0; // đếm số đỉnh của đồ thị
    while (Q.size() > 0)
    {
        // lấy ra cặp ở đỉnh hàng đợi
        pair<int, int> top = Q.top();
        Q.pop();

        int W = top.first;  // Trọng số nhỏ nhất hiện tại
        int u = top.second; // Đỉnh hiện tại

        if (visited[u])
            continue;
        d += W;
        ++cnt;             // tăng số lượng cạnh đã duyệt
        visited[u] = true; // Đánh dấu đỉnh u đã thăm

        // duyệt danh sách kề của u
        for (auto it : adj[u])
        {
            // it.first : đỉnh kề với đỉnh u
            // it.second : trọng số giữa 2 đỉnh đó
            int v = it.first;
            int w = it.second;
            if (visited[v] == false)
                Q.push({w, v}); // Tiếp tục đẩy trọng số và cạnh kề của đỉnh u vào trong hàng đợi
        }
    }
    // nếu cnt != n thì => đồ thị không liên thông,
    // tức là prim không duyệt hết tất cả các đỉnh

    // In ra giá trị cây khung cực tiểu
    cout << d << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        khoitao();
        PRIM(1);
    }
}