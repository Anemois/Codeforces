//10/29/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].first;
        vect[i].second = i;
    }
        
    sort(vect.begin(), vect.end());

    vector<int> ans(n);
    int cnt = n;
    for(auto& i : vect){
        ans[i.second] = n;
        n--;
    }
    for(auto& i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}
/*
process:
    this one is easy
    if one goes from small to big
    the other goes   big to small
    then there will never be the same ones
*/