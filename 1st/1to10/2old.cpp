#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
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
int numdiv(int n){
    if (n <= 3){
        return 1;
    }
    int tmp, res;
    map<int, int>  dic;
    tmp = n;
    for(int i = 2; i <= sqrt(n);++i){

        while(tmp == i * (tmp/ i)){
            if(dic.count(i)){
                dic[i] = dic[i] + 1;
            }else{
                dic[i] = 2;
            }
            tmp = tmp / i;
        }
    }
    res = 1;
    for(auto const& x:dic){
        res = res * x.second;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int tmp, res;
    res = 0;
    rep(i, n){
        tmp = i + 1;
        if(tmp % 2 == 0){
            continue;
        }
        if (numdiv(tmp) == 8){
            res++;
        }        
        
    }
    cout << res << endl;
    return 0;
}

