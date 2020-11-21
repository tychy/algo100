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
    int n;
    cin >> n;
    cout << n << ":";
    int prev = 2;
    int sqrtn = int(sqrt(n));
    // whileの分岐に余計なことを書くと重い
    while (prev <= sqrtn)
    {
        while (n % prev == 0)
        {
            cout << " " << prev;
            n = n / prev;
        }
        prev++;
    }
    if (n != 1)
    {
        cout << " " << n;
    }
    cout << endl;
}