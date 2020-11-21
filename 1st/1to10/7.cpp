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
void printer(vector<int> v)
{
    rep(i, v.size())
    {
        cout << v[i] << " ,";
    }
    cout << endl;
}
bool find(pair<int, int> p, const vector<int> &x, const vector<int> &y)
{
    auto iterl = lower_bound(x.begin(), x.end(), p.first);
    int idx = distance(x.begin(), iterl);
    for (int i = idx; i < x.size(); i++)
    {
        if (x[i] != p.first)
        {
            return false;
        }
        if (y[i] == p.second)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, inputx, inputy;
    vector<pair<int, int>> vp;
    int score = 0;
    int area;
    cin >> n;
    rep(i, n)
    {
        cin >> inputx >> inputy;
        vp.push_back(make_pair(inputx, inputy));
    }
    //sort vp by x
    sort(vp.begin(), vp.end());
    vector<int> x(n), y(n);
    rep(i, n)
    {
        x[i] = vp[i].first;
        y[i] = vp[i].second;
    }
    pair<int, int> pa, pb, pc, pd;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pa = vp[i];
            pb = vp[j];
            pc = make_pair(pa.first + pa.second - pb.second, pa.second + pb.first - pa.first);
            pd = make_pair(pb.first + pa.second - pb.second, pb.second + pb.first - pa.first);
            area = (pb.first - pa.first) * (pb.first - pa.first) + (pb.second - pa.second) * (pb.second - pa.second);
            if (find(pc, x, y) and find(pd, x, y))
            {
                if (area > ans)
                {
                    ans = area;
                }
            }
        }
    }
    cout << ans << endl;
}