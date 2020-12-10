#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main()
{
    int n;
    cin >> n;
    for (int idx = 0; idx < n; idx++)
    {
        string a, b;
        cin >> a;
        cin >> b;
        vector<vector<int>> dp(a.size() + 1);
        for (int j = 0; j < a.size() + 1; j++)
        {
            vector<int> tmp(b.size() + 1, 0);
            dp[j] = tmp;
        }
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if (a[i] == b[j])
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }

        cout << dp[a.size()][b.size()] << endl;
    }

    return 0;
}