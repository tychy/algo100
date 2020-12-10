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
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    vector<int> m(q);
    vector<bool> ans(q, false);

    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }
    bool flag = false;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int sums = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                sums += a[i];
            }
        }
        for (int i = 0; i < q; i++)
        {
            if (m[i] == sums)
            {
                ans[i] = true;
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (ans[i])
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}