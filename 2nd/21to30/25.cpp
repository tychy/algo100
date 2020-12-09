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
void dfs(int i, int j, int h, int w, vector<vector<int>> &c)
{
    if (i < 0 or i >= h or j < 0 or j >= w or c[i][j] == 0)
    {
        return;
    }
    c[i][j] = 0;
    dfs(i + 1, j, h, w, c);
    dfs(i - 1, j, h, w, c);
    dfs(i, j + 1, h, w, c);
    dfs(i, j - 1, h, w, c);
    dfs(i + 1, j + 1, h, w, c);
    dfs(i + 1, j - 1, h, w, c);
    dfs(i - 1, j + 1, h, w, c);
    dfs(i - 1, j - 1, h, w, c);
    return;
}
int main()
{
    while (true)
    {
        int w, h;
        int ans = 0;
        cin >> w >> h;
        if (w == 0 and h == 0)
        {
            break;
        }
        vector<vector<int>> c(h);
        for (int i = 0; i < h; i++)
        {
            vector<int> v(w);
            for (int j = 0; j < w; j++)
            {
                cin >> v[j];
            }
            c[i] = v;
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (c[i][j] == 1)
                {
                    ans++;
                    dfs(i, j, h, w, c);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}