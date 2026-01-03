//11/4/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int go(int& n, int keep){
    int ret=0, mx = 0;
    for(int i=1; i<=n-keep; i++){
        //cout << i << " " << i << ", ";
        ret += i*i;
        mx = max(mx, i*i);
    }
    int k = n-keep+1;
    for(int i=0; i<keep; i++){
        //cout << (k+i) << " " << (n-i) << ", ";
        ret += (k+i)*(n-i);
        mx = max(mx, (k+i)*(n-i));
    }
    //cout << "\n";
    return ret - mx;
}

int solve(){
    int n, mx=0;
    cin >> n;
    for(int i=0; i<=n; i++){
        mx = max(mx, go(n, i));
    }
    return mx;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cout << solve() << "\n";
    }
}