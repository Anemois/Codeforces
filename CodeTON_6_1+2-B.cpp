//10/29/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int a, b=0, x;
    cin >> a;
    for(int i=1; i<n; i++){
        cin >> x;
        a ^= x;
    }
    for(int i=0; i<m; i++){
        cin >> x;
        b |= x;
    }
    if(n%2 == 0){
        cout << (a & (~b)) << " " << a;
    }
    else{
        cout << a << " " << (a | b);
    }
    cout << "\n";
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve();
    }
    return 0;
}