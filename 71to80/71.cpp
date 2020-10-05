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
ll pow_fast(ll m, ll n)
{
    ll mod = 1000000007;
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return pow_fast((m * m) % mod, n / 2);
    }
    else
    {
        return (m * pow_fast((m * m) % mod, n / 2)) % mod;
    }
}
void print_vector(const vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}
int main()
{
    // modを定数にしたい
    ll n, q, input, value, ans, sums;
    ll mod = 1000000007;
    cin >> n >> q;
    vector<ll> a;
    vector<ll> c;
    vector<ll> cost;
    c.push_back(0);
    rep(i, n)
    {
        cin >> input;
        a.push_back(input);
    }
    rep(i, q)
    {
        cin >> input;
        c.push_back(input - 1);
    }
    sums = 0;
    cost.push_back(sums);
    rep(i, n - 1)
    {
        sums += pow_fast(a[i], a[i + 1]);
        cost.push_back(sums);
    }
    c.push_back(0);
    ans = 0;
    //print_vector(a);
    // print_vector(c);
    //print_vector(cost);

    rep(i, q + 1)
    {
        ans = (ans + abs(cost[c[i]] - cost[c[i + 1]])) % mod;
    }
    cout << ans << endl;
}
