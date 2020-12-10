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
    int n, w_th;
    cin >> n >> w_th;
    vector<int> vecv(n), vecw(n);
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> vecv[i];
        cin >> vecw[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        vector<int> tmp(w_th + 1, 0);
        dp[i] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w_th; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - vecw[i] >= 0)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - vecw[i]] + vecv[i]);
            }
        }
    }
    cout << dp[n][w_th] << endl;
    return 0;
}