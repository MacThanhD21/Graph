#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;

	int G[n + 1][n + 1] = {0};
	int u, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}
}