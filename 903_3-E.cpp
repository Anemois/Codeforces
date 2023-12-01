//2023/12/1 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> vect(n), dp(n+1, INT_MAX);

    for(int i=0; i<n; i++){
        cin >> vect[i];
    }
    dp[0] = 0;
    if(vect[0]+1 <= n){
        dp[vect[0]+1] = 0;
    }
    for(int i=1; i<n; i++){
        dp[i] = min(dp[i], dp[i-1]+1);
        if(i+vect[i]+1 <= n){
            dp[vect[i]+i+1] = min(dp[vect[i]+i+1], dp[i]);
        }
    }
    return min(dp[n], dp[n-1]+1);
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}
/*
celebrate : 100'th question!!!! WOOOO
*/