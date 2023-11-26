//11/24/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, x, ans = 0;
    cin >> n >> x;
    int t;
    int last = 0;
    for(int i=0; i<n; i++){
        cin >> t;
        ans = max(ans, t-last);
        last = t;
    }
    ans = max(ans, (x-last)*2);
    return ans;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}