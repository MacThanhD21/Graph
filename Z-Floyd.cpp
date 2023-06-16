#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int n, m, q;
int floyd[1005][1005];

/*
- floyd : tìm đường đi ngắn nhất giữa mọi cặp đỉnh trên đồ thị (i -> j)
thông qua đỉnh k
*/
void inp()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                floyd[i][j] = 0;
            else
                floyd[i][j] = 1e9;
        }
    }
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        floyd[x][y] = floyd[y][x] = z;
    }
}

void FLOYD()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
}

void solve()
{
    inp();
    FLOYD();
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << floyd[x][y] << "\n";
    }
}
int main()
{
    solve();
}
