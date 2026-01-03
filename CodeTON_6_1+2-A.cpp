//10/29/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k, x;
    cin >> n >> k >> x;
    if(x < k-1 || n < k) return -1;
    int ans = 0;
    for(int i=0; n > 0 && i<k; i++){
        ans += i;
        n--;
    }
    //cout << ans << " " << n << "\n";
    return ans + n*(x == k ? x-1 : x);
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << solve() << "\n";
    }
    return 0;
}