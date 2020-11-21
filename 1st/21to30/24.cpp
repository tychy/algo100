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
const int MOD = 1000000007;
void visit(int idx, Graph g, int &time, vector<int> &visited, vector<int> &s, vector<int> &e)
{
    if (visited[idx] == 1)
    {
        return;
    }
    s[idx] = ++time;
    visited[idx] = 1;
    for (int i = 0; i < g[idx].size(); i++)
    {
        visit(g[idx][i] - 1, g, time, visited, s, e);
    }
    e[idx] = ++time;
    return;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph g(n);
    rep(i, n)
    {
        int u, k;
        cin >> u >> k;
        vector<int> v(k);
        rep(j, k) cin >> v[j];
        g[i] = v;
    }

    vector<int> visited(n, 0), s(n), e(n);
    int time = 0;
    rep(i, n)
    {
        if (visited[i] == 0)
        {
            visit(i, g, time, visited, s, e);
        }
    }
    rep(i, n)
    {
        cout << i + 1 << " " << s[i] << " " << e[i] << endl;
    }
}