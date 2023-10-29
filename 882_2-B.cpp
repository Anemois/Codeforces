//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, mn = INT_MAX;
    cin >> n;
    vector<int> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i];
        mn = mn&vect[i];
    }
    int cnt = 0, now = INT_MAX;
    for(int i=0; i<n; i++){
        now = now & vect[i];
        if(now == mn){
            cnt++;
            now = INT_MAX;
        }
    }
    if(mn == 0)
        return cnt;
    else
        return 1;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}