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
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}