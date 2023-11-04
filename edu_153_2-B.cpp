//11/3/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool check(int& n, int& m, int& a, int& k){
    int t = n/k;
    if(abs(t*k - n) > abs((t+1)*k - n))
        t++;
    int diff = abs(n - t*k);
    return max(diff-a, 0LL) + t <= m;
}

int solve(){
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    int t = min(n/k, b);
    if(t < b && abs(t*k - n) > abs((t+1)*k - n))
        t++;
    int diff = abs(n - t*k);
    int l = 0, r = 100000000;
    while(l < r){
        int m = (l+r)/2;
        if(check(diff, m, a, k))
            r = m;
        else
            l = m+1;
    }
    return l;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}