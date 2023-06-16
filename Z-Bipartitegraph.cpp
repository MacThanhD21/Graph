#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1000];   // danh sách kề của đồ thị
int color[1000];         // mảng chứa màu của các đỉnh
bool isBipartite = true; // biến đánh dấu đồ thị có phải là đồ thị hai phía hay không

void dfs(int v, int c)
{
    color[v] = c;
    for (int u : adj[v])
    {
        // Nếu Màu của đỉnh u giống màu đỉnh cha
        // => return false;
        if (color[u] == c)
        {
            isBipartite = false;
        }
        if (color[u] == 0)
        {
            dfs(u, -c);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i, 1);
        }
    }
    if (isBipartite)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}