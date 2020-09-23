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
    int n, num, ans, res;
    cin >> n;
    res = 0;
    for(int i=1;i<=n;i+=2){
        ans = 1;
        vector<int> x(i+1, 0);
        num = i;
        for(int j=2;j<=i;j++){
            while(num%j == 0){
                x.at(j)++;
                num/=j;
            }
        }
        for(int j=2;j<=i;j++){
            ans *= x.at(j) + 1;
        }
        if (ans==8){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}

