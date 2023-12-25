//2023/12/24
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k, d;
    cin >> n >> k >> d;
    int mx=0;
    vector<int> vect(n+1), loop(k);
    for(int i=1; i<=n; i++){
        cin >> vect[i];
        if(vect[i] == i)
            mx++;
    }
    mx += (d-1)/2;
    for(int i=0; i<k; i++)
        cin >> loop[i];
    int j=0;
    for(int t=1; t<=min(5000LL, d-1); t++){
        int now=0;
        int N = loop[j++];
        if(j == k) j=0;
        for(int i=1; i<=N; i++){
            vect[i]++;
            if(vect[i] == i)
                now++;
        }
        for(int i=N+1; i<=n; i++){
            if(vect[i] == i)
                now++;
        }
        now += (d-t-1)/2;
        mx = max(mx, now);
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