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
        //偶数
        return pow_fast((m * m) % mod, n / 2);
    }
    else
    {
        return (m * pow_fast((m * m) % mod, n / 2)) % mod;
    }
}
int main()
{
    ll m, n;
    cin >> m >> n;

    cout << pow_fast(m, n) << endl;
}