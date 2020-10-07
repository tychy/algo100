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
void print_vector(const vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll score;
    cin >> n;

    ll ans = 0;
    vector<int> a(n), b(n), c(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    rep(i, n)
    {
        score = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        score *= c.end() - upper_bound(c.begin(), c.end(), b[i]);

        ans += score;
    }
    cout << ans << endl;
}
