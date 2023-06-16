#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ms(a) memset(a, false, sizeof(a))

const int N = 1005;

int parent[1001];
int sz[1001]; // lưu lại số lượng các thành phần liên thông sau khi gộp

void generate()
{
    for (int i = 1; i <= 1000; i++)
    {
        // Ban đầu cập nhật cha của đỉnh i là chính nó
        parent[i] = i;
        sz[i] = 1;
    }
}

// Hàm Find : trả về đại diện của đỉnh u;
int Find(int u)
{
    if (u == parent[u])
        return u;
    else
        // vừa gán, vừa thay đổi giá trị của Find(parent[u]) cho parent[u]
        return parent[u] = Find(parent[u]);
}

// Gộp 2 đỉnh x, y : nếu gộp được => True , else => false
bool Union(int x, int y)
{
    // Tìm đại diện (cha) của 2 thằng x, y
    x = Find(x);
    y = Find(y);
    // Nếu 2 thằng có cùng cha => không gộp được
    // => false
    if (x == y)
        return false;
    if (sz[x] < sz[y])
    {
        sz[y] += sz[x];
        // thằng nào lớn hơn làm cha
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        sz[x] += sz[y];
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}