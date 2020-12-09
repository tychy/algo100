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
int main()
{
    int n, cur;
    cin >> n;
    int ans = 0;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        cur = i;
        vector<int> yaku(i + 1, 0);
        while (cur != 1)
        {
            for (int j = 3; j <= cur; j++)
            {
                if (cur % j == 0)
                {
                    cur /= j;
                    yaku[j]++;
                    break;
                }
            }
        }
        int sums = 1;
        for (int idx = 0; idx < i + 1; idx++)
        {
            /* code */
            if (yaku[idx] != 0)
            {
                sums *= yaku[idx] + 1;
            }
        }
        if (sums == 8)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}