//2023/12/16 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int cnt=0, base=0;
    vector<int> place(m+1);
    place[0] = 1-k;
    for(int i=1; i<=m; i++){
        cin >> place[i];
        base+=(place[i]-place[i-1]+k-1)/k;
    }
    base+=(n-place[m])/k;
    int last = 1-k;
    for(int i=1; i<m; i++){
        if((place[i]-place[i-1]+k-1)/k + (place[i+1]-place[i]+k-1)/k > (place[i+1] - place[i-1]+k-1)/k){
            cnt++;
        }
    }
    if((place[m]-place[m-1]+k-1)/k + (n+1-place[m]+k-1)/k > (n+1 - place[m-1]+k-1)/k){
        cnt++;
    }

    if(cnt == 0)
        cout << base << " " << m;
    else
        cout << base-1 << " " << cnt;
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}