#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define Graph vector<vector<int>>
#define iterG(next_v, G, v) for(auto next_v : G[v]

void dfs(int idx, Graph &g, int &t, vector<int> &d, vector<int> &f)
{
    //G??
    if (d[idx] != 0)
    {
        return;
    }
    d[idx] = t;
    t++;
    vector<int> cur = g[idx];
    for (int i = 0; i < cur.size(); i++)
    {
        dfs(cur[i], g, t, d, f);
    }
    f[idx] = t;
    t++;
}

int main()
{
    int n;
    int t = 1;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> d(n, 0), f(n, 0);
    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;

        vector<int> v(k);
        for (int j = 0; j < k; j++)
        {
            /* code */
            cin >> v[j];
            v[j]--;
        }
        g[u - 1] = v;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0)
        {
            dfs(i, g, t, d, f);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}