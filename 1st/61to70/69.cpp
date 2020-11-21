#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
#define ll long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main()
{
    int q, inputl, inputr, sim, ans;
    vector<int> l, r;
    cin >> q;
    rep(i, q)
    {
        cin >> inputl >> inputr;
        l.push_back(inputl);
        r.push_back(inputr);
    }
    //エラトステネスのふるい
    int size = 100001;
    vector<int> furui(size, 1); //素数は1
    furui[0] = 0;
    furui[1] = 0;
    for (int i = 2; i <= sqrt(size); i++)
    {
        if (furui[i] == 1)
        {
            int j = 2 * i;
            while (j < size)
            {
                furui[j] = 0;
                j += i;
            }
        }
    }
    vector<int> ln(size, 0);
    ans = 0;
    for (int i = 3; i < size; i++)
    {
        if (i % 2 == 0)
        {
            ln[i] = ans;
        }
        else if (furui[i] == 1 and furui[(i + 1) / 2] == 1)
        {
            ans++;
            ln[i] = ans;
        }
        else
        {
            ln[i] = ans;
        }
    }
    rep(i, q)
    {
        inputl = l[i];
        inputr = r[i];
        cout << ln[inputr] - ln[inputl - 1] << endl;
    }
}