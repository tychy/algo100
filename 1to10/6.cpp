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
    int n, flag;
    int ans = 0;
    string s, target;
    cin >> n;
    cin >> s;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                flag = 0;
                target = to_string(i) + to_string(j) + to_string(k);
                for (int idx = 0; idx < s.size(); idx++)
                {
                    if (s[idx] == target[flag])
                    {
                        flag++;
                    }
                    if (flag == 3)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}