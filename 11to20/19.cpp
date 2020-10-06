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
const int MOD = 1000000007;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll d, n, m, input;
    ll ans = 0;
    vector<ll> k, d_ls;
    cin >> d;
    cin >> n;
    cin >> m;
    d_ls.push_back(0);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> input;
        d_ls.push_back(input);
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> input;
        k.push_back(input);
    }
    d_ls.push_back(d);
    sort(d_ls.begin(), d_ls.end());
    ll target, l, r, mid;
    for (ll i = 0; i < m; i++)
    {
        target = k[i];
        l = 0;
        r = n + 1;
        while (l != r)
        {
            mid = (l + r) / 2;
            if (target >= d_ls[mid] and target < d_ls[mid + 1])
            {
                ans += min(target - d_ls[mid], d_ls[mid + 1] - target);
                break;
            }
            else if (target < d_ls[mid])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    cout << ans << endl;
}