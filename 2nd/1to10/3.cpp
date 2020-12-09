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
    string s;
    cin >> s;
    int ans = 0;
    int cur;
    vector<int> n(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' or s[i] == 'T' or s[i] == 'G' or s[i] == 'C')
        {
            n[i] = 1;
        }
    }
    cur = 0;
    for (int i = 0; i < s.size(); i++)
    {
        cur = (cur + 1) * n[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}