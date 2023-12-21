//2023/12/21 difficulty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    int last = -1, x=-1;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x-1 != last){
            mp[(x-1) - i] = i;
        }
        last = x;
    }
    mp[INT64_MAX] = n;
    // for(auto& i : mp){
    //     cout << i.first << " " << i.second << " - ";
    // }
    int now=1;
    while(k--){
        auto p = mp.lower_bound(now);
        now += (*p).second;
    }
    return now;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}