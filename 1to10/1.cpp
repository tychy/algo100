#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, sums, ans;
    vector<int> a;
    while(true){
        cin >> n >> x;
        if (n == 0 && x ==0){
            break;
        }
        ans = 0;
        rep(i, n-2){
            for(int j=i+1;j<n-1;j++){
                sums = x - (i + j + 2);
                if(sums > j+1 && sums <= n){
                    ans += 1;
                }
            }
        }
        a.push_back(ans);
    }
    rep(i, a.size())
        cout << a.at(i) << endl;

    return 0;
}

