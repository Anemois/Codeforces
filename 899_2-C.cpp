//2023/11/29 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool check(int x){
    return x >= 0;
}

int solve(){
    int n;
    cin >> n;
    int x, ans=0;
    cin >> x;
    if(n == 1)
        return max(0LL, x);
    int two[2];
    cin >> two[1];
    two[0] = x;
    ans += max(0LL, two[0]) + max(0LL, two[1]);
    for(int i=2; i<n; i++){
        cin >> x;
        ans += max(0LL, x);
    }

    return two[0] >= 0 || two[1] <= 0 ? ans : ans - max(0LL, min(-two[0], two[1]));
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}