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
    int n, m;
    ll input, ans, cur;
    cin >> n >> m;
    vector<vector<ll>> a;
    rep(i, n)
    {
        vector<ll> tmp;

        rep(j, m)
        {
            cin >> input;
            tmp.push_back(input);
        }
        a.push_back(tmp);
    }
    ans = 0;
    rep(i, m - 1)
    {
        for (ll j = i + 1; j < m; j++)
        {
            cur = 0;
            rep(k, n)
            {
                cur += max(a[k][i], a[k][j]);
            }
            if (cur > ans)
                ans = cur;
        }
    }
    cout << ans << endl;
    return 0;
}
