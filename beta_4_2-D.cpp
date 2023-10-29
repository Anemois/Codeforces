//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int w, h, i;
};

void solve(){
    int n;
    P now;
    cin >> n >> now.w >> now.h;
    vector<P> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].w >> vect[i].h;
        vect[i].i = i+1;
    }
    sort(vect.begin(), vect.end(), [](const P& a, const P& b){
        if(a.w == b.w) return a.h < b.h;
        return a.w < b.w;
    });
    struct
    vector<pair<int, int>> dp(n);
    for(int i=n-1; i>=0; i--){
        int mx = 0, index = i;
        for(int j=i+1; j<n; j++){
            if(dp[j].first > mx && vect[j].h > vect[i].h && vect[j].w > vect[i].w){
                index = j;
                mx = dp[j].first;
            }
        }
        dp[i].first = mx + 1;
        dp[i].second = index == i ? -1 : index;
    }

    int mx = 0, index = -1;
    for(int i=0; i<n; i++){
        if(dp[i].first > mx && vect[i].h > now.h && vect[i].w > now.w){
            mx = dp[i].first;
            index = i;
        }
    }
    if(mx == 0)
        cout << 0 << "\n";
    else{
        cout << mx << "\n";
        while(index != -1){
            cout << vect[index].i << " ";
            index = dp[index].second;
        }
    }
    cout << "\n";
}

signed main(){
    Anemoi
    solve();
}