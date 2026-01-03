//2023/12/21
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=n; i>k+1; i--)
        cout << i << " ";
    for(int i=1; i<=k+1; i++)
        cout << i << " ";
    
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}