//2023/12/3 difficulty:1700
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define FOR(a, b) for(int a=0; a<(b); a++)
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> vect(n);
    FOR(i, n) cin >> vect[i];
    FOR(t, q){
        vector<int> temp = vect;
        int ans=0;
        int x;
        cin >> x;
        for(int i=60; i>=0; i--){
            int sum=0;
            vector<int> temp2 = temp;
            FOR(j, n){
                if(!((temp[j]>>i)&1)){
                    sum += (1LL<<i) - (temp[j]%(1LL<<i));
                    temp2[j] = 0;
                    if(sum > x) break;
                }
            }
            if(x >= sum){
                //cout << sum << "\n";
                temp = temp2;
                ans += 1LL<<i;
                x -= sum;
            }
        }
        cout << ans << "\n";
    }
}

signed main(){
    Anemoi
    int t = 1;
    for(int i=0; i<t; i++)
        solve();
}