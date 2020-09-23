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
    int ans = 0;
    int cur;
    string s;
    cin >> s;
    rep(i, s.size()-1){
        for(int j=i+1;j <= s.size();j++){
            cur = 0;
            for(int k=i;k<=j;k++){
                if(s[k] != 'A' ||s[k] != 'G' ||s[k] != 'T' ||s[k] != 'C'){
                    break;
                }
                if()
            }
        }
    }
    return 0;
}

