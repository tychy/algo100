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
int main()
{
    int n;
    cin >> n;
    vector<int> fib(n + 1);
    if (n <= 1)
    {
        cout << 1 << endl;
        return 0;
    }
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n] << endl;
    return 0;
}