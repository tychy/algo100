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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    vector<vector<int>> dp(m + 1);
    for (int i = 0; i < m + 1; i++)
    {
        if (i == 0)
        {
            vector<int> tmp(n + 1, 0);
            for (int j = 0; j <= n; j++)
            {
                tmp[j] = j;
            }
            dp[i] = tmp;
        }
        else
        {
            vector<int> tmp(n + 1, 0);
            dp[i] = tmp;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - c[i] >= 0)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - c[i]] + 1);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - c[i]] + 1);
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}