#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cin.ignore();
    vector<int> G[1005];

    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        string tmp;
        stringstream ss(s);
        while (ss >> tmp)
        {
            G[i].push_back(stoi(tmp));
            // G[stoi(tmp)].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(G[i].begin(), G[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : G[i])
        {
            cout << i << " " << x << "\n";
        }
    }
}