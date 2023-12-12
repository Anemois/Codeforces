//2023/12/12
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> vect(n);
    int mn = INT64_MAX;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        mn = min(mn, vect[i]);
    }
        
    if(k >= 3) return 0;
    sort(vect.begin(), vect.end());
    for(int i=0; i<n-1; i++)
        mn = min(mn, abs(vect[i]-vect[i+1]));
    if(k==1)
        return mn;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            int x = abs(vect[i] - vect[j]);
            auto p = lower_bound(vect.begin(), vect.end(), x);
            mn = min(mn, (*p)-x);
            if(p!=vect.begin()){
                p--;
                mn = min(mn, x-(*p));
            }
        }
    }
    return mn;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}