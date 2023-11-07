//11/4/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int N = n*(n-1)/2;
    vector<int> b(N);
    for(int i=0; i<N; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    int j = -1;
    for(int i=n-1; i>=0; i--){
        j += i;
        cout << b[j] << " ";
    }
    cout << "\n";
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}