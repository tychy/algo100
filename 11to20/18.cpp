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
    int n, q, input;
    vector<int> s, t;
    cin >> n;
    rep(i, n)
    {
        cin >> input;
        s.push_back(input);
    }
    cin >> q;
    rep(i, q)
    {
        cin >> input;
        t.push_back(input);
    }
    //|l,r)
    int l, r;
    int mid, target;
    int ans = 0;
    rep(i, q)
    {
        target = t[i];
        l = 0;
        r = n;
        while (l != r)
        {
            //cout << l << " : " << r << endl;
            mid = (l + r) / 2;
            if (s[mid] == target)
            {
                ans++;
                break;
            }
            else if (s[mid] > target)
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