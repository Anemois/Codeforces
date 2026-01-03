//11/8/2023 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    cout << min(n+1, m==1?0:m) << "\n";
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            cout << (i+j + (i%m == 0))%m << " ";
        }
        cout << "\n";
    }
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}