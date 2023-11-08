//11/8/2023 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

struct P{
    int val, pow;
};

int go(int x){
    int ret = 1, two = 2;
    while(x > 0){
        if(x&1)
            ret = (ret*two)%MOD;
        x = x>>1;
        two = (two*two)%MOD;
    }
    return ret%MOD;
}

int solve(){
    int n1, n2;
    cin >> n1;
    vector<P> v1(n1);
    for(int i=0; i<n1; i++)
        cin >> v1[i].val;
    for(int i=0; i<n1; i++)
        cin >> v1[i].pow;
    cin >> n2;
    vector<P> v2(n2);
    for(int i=0; i<n2; i++)
        cin >> v2[i].val;
    for(int i=0; i<n2; i++)
        cin >> v2[i].pow;
    
    map<int, int> mp;
    for(auto& i : v1)
        mp[i.val] = i.pow;
    for(auto& i : v2){
        mp[i.val] -= i.pow;
        if(mp[i.val] < 0)
            return 0;
        if(mp[i.val] == 0)
            mp.erase(i.val);
    }
    return go(mp.size());
}

signed main(){
    Anemoi
    cout << solve();
}