//10/29/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    int ans = INT_MAX, x;
    for(int i=0; i<n; i++){
        cin >> x;
        ans = min(ans, abs(x));
    }
    return ans;
}

signed main(){
    Anemoi
    cout << solve();
}
/*
process:
    just find the closest to 0...
*/