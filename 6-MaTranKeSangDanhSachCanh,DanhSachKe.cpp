#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int G[n + 1][n + 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> G[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (G[i][j])
			{
				cout << i << " " << j << "\n";
			}
		}
	}
	cout << "\n";

	vector<int> adj[100];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (G[i][j])
			{
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << i << " : ";
		for (auto x : adj[i])
		{
			cout << x << " ";
		}
		cout << "\n";
	}
}