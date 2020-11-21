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
void visit(int idx, int &time, vector<int> &s, vector<int> &e, const vector<vector<int>> &v)
{
    if (s[idx] != 0)
    {
        return;
    }
    s[idx] = ++time;
    rep(i, v[idx].size())
    {
        visit(v[idx][i], time, s, e, v);
    }
    e[idx] = ++time;
    return;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    rep(i, n)
    {
        int u, k, input;
        cin >> u >> k;
        vector<int> inputv(k);
        rep(j, k)
        {
            cin >> input;
            inputv[j] = input - 1;
        }
        v[i] = inputv;
    }
    vector<int> s(n, 0), e(n, 0);
    int time = 0;
    rep(i, n)
    {
        if (s[i] != 0)
        {
            continue;
        }
        visit(i, time, s, e, v);
    }
    //answer
    rep(i, n)
    {
        cout << i + 1 << " " << s[i] << " " << e[i] << endl;
    }
}