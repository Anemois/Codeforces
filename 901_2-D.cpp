//2023/12/9 difficulty:1600
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0; i<n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    int mx = 0;
    for(auto& i : t){
        if(i == mx)
            mx++;
    }
    vector<int> cnt(mx);
    vector<pair<int, int>> vect;
    vect.push_back(make_pair(0, mx));
    for(int i=0; i<n; i++){
        if(t[i] < mx)
            cnt[t[i]]++;
    }
    
    for(int i=mx-1; i>=0; i--){
        int mn = INT_MAX;
        for(auto& j : vect){
            mn = min(mn, j.first + (cnt[i]-1)*(j.second) + i);
        }
        while(!vect.empty() && mn <= vect.back().first)
            vect.pop_back();
        vect.push_back(make_pair(mn, i));
    }
    return vect.back().first;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}