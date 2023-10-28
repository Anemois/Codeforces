#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#pragma GCC optimize("O2")
using namespace std;

vector<bool> ok(200001, true);

void solve(){
    int n;
    cin >> n;
    fill(ok.begin(), ok.begin()+n, true);
    cout << 1 << " ";
    for(int i=2; i<=n; i++){
        if(!ok[i]) continue;
        int x = i;
        while(x <= n){
            cout << x << " ";
            x *=2;
            ok[x] = false;
        }
    }
    cout << "\n";
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}