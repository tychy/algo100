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
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> n_ls, x_ls;
    while (true)
    {
        int tmpn, tmpx;
        cin >> tmpn >> tmpx;
        if (tmpn == 0 and tmpx == 0)
        {
            break;
        }
        n_ls.push_back(tmpn);
        x_ls.push_back(tmpx);
    }
    rep(idx, n_ls.size())
    {
        int n, x;
        n = n_ls[idx];
        x = x_ls[idx];
        int ans = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int k = x - (i + j);
                if (k > j and k <= n)
                {
                    ans++;
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
