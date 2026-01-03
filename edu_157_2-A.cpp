//11/3/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int c, k, t;
    cin >> c >> k >> t;
    if(k <= c)
        return c;
    
    c = min(k, c+t);

    return k + k-c;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}