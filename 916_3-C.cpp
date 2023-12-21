//2023/12/21
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    priority_queue<int> pq;
    int mx = 0;
    int sum = 0;
    int x;
    for(int i=1; i<=min(k, n); i++){
        sum += a[i];
        pq.push(b[i]);
        mx = max(mx, sum + (k-i)*pq.top());
    }
    return mx;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}