//11/3/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    n *= 2;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end());
    int ans = 0;
    int N = n/2-1;
    for(int i=0; i<N; i++){
        ans += vect[i+1] - vect[i] + vect[n-i-1] - vect[n-i-2]; 
    }
    N++;
    cout << ans << "\n";
    for(int i=0; i<N; i++){
        cout << vect[i] << " " << vect[n-i-1] << "\n";
    }
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}