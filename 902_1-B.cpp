//2023/12/8 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

int solve(){
    int n;
    cin >> n;
    vector<int> vect1(n+1), vect(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> vect1[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            vect[i] = max(vect1[j], vect[i]);
        }
    }
    sort(vect.begin()+1, vect.end());
    int two = 1, ans=0;
    for(int i=1; i<=n; i++){
        ans = (ans + vect[i]*two)%MOD;
        two = (two*2)%MOD;
    }
    return ans%MOD;
}

signed main(){
    Anemoi
    int t = 1;
    for(int i=0; i<t; i++)
        cout << solve();
}