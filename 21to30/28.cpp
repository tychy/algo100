#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
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
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int sy, sx, gy, gx, r, c, cur;
    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;
    vector<string> m(r);
    vector<vector<int>> v(r, vector<int>(c, 0));
    queue<pair<int, int>> que;
    rep(i, r)
    {
        cin >> m[i];
    }
    que.push(make_pair(sy - 1, sx - 1));
    while (!que.empty())
    {
        pair<int, int> p = que.front();
        cur = v[p.first][p.second];
        for (int x = -1, y = 0, i = 0; i < 4; x += y, y = x - y, x = y - x, ++i)
        {
            if (p.first + y < 0 or p.first + y >= r or p.second + x < 0 or p.second + x >= c)
            {
                continue;
            }
            if (v[p.first + y][p.second + x] != 0 or m[p.first + y][p.second + x] == '#')
            {
                continue;
            }
            v[p.first + y][p.second + x] = cur + 1;
            que.push(make_pair(p.first + y, p.second + x));
        }
        que.pop();
    }
    cout << v[gy - 1][gx - 1] << endl;
}