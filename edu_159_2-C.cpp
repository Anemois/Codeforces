//2023/12/3
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];

    if(vect.size() == 1)
        return 1;

    sort(vect.begin(), vect.end());

    int x = vect[1] - vect[0];

    for(int i=2; i<n; i++){
        x = __gcd(x, vect[i]-vect[i-1]);
    }
    //cout << x << "\n";
    int gap=vect[0]-x;
    int ans=0;
    for(int i=0; i<n-1; i++){
        if(vect[i] != vect[i+1]-x){
            gap = vect[i+1]-x;
        }
        ans += (vect.back() - vect[i])/x;
    }

    ans += (vect.back() - gap)/x;
    
    return ans;
}
signed main(){
    Anemoi
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}