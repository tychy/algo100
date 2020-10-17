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
bool isvalid(pair<int, int> a)
{
    return a.first >= 0 and a.second >= 0;
}
pair<int, int> minus_pair(pair<int, int> a, pair<int, int> b)
{
    return make_pair(a.first - b.first, a.second - b.second);
}
pair<int, int> plus_pair(pair<int, int> a, pair<int, int> b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> t_pair(pair<int, int> a)
{
    return make_pair(a.second, -a.first);
}
pair<int, int> inv_pair(pair<int, int> a)
{
    return make_pair(-a.first, -a.second);
}
bool isexist(pair<int, int> a, map<pair<int, int>, int> mp)
{
    if (not isvalid(a))
    {
        return false;
    }
    auto itr = mp.find(a);
    return itr != mp.end();
}
int issquare(pair<int, int> a, pair<int, int> b, map<pair<int, int>, int> v)
{
    pair<int, int> diff = minus_pair(a, b);
    pair<int, int> p_ver = t_pair(diff);
    pair<int, int> m_ver = inv_pair(p_ver);
    int area = diff.first * diff.first + diff.second * diff.second;
    if (isexist(plus_pair(a, p_ver), v) and isexist(plus_pair(b, p_ver), v))
    {
        return area;
    }
    else if (isexist(plus_pair(a, m_ver), v) and isexist(plus_pair(b, m_ver), v))
    {
        return area;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, inputx, inputy;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> vp;
    int score = 0;
    int area;
    cin >> n;
    rep(i, n)
    {
        cin >> inputx >> inputy;
        mp[make_pair(inputx, inputy)] = 1;
        vp.push_back(make_pair(inputx, inputy));
    }
    rep(i, n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            area = issquare(vp[i], vp[i + 1], mp);
            if (area > score)
            {
                score = area;
            }
        }
    }
    cout << score << endl;
}