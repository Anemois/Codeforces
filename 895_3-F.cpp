//2023/12/13 difficulty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

pair<int, int> go(vector<int>& next, vector<int>& val, int begin, int p){
    if(p == begin)
        return make_pair(val[p], p);
    pair<int, int> x = go(next, val, begin, next[p]);
    if(x.first < val[p])
        return x;
    return make_pair(val[p], p);
}

void solve(){
    int n;
    cin >> n;
    vector<int> next(n+1), val(n+1), cnt(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> next[i];
        cnt[next[i]]++;
    }
    queue<int> pend;
    for(int i=1; i<=n; i++){
        cin >> val[i];
        if(cnt[i] == 0) pend.push(i);
    }
        
    while(!pend.empty()){
        int& p = pend.front();
        if(--cnt[next[p]] == 0)
            pend.push(next[p]);
        cout << p << " ";
        pend.pop();
    }
    //cout << " --- ";
    for(int i=1; i<=n; i++){
        if(cnt[i] != 0){
            pair<int, int> x = go(next, val, i, next[i]);
            int p=next[x.second];
            while(p != x.second){
                cnt[p] = 0;
                cout << p << " ";
                p = next[p];
            }
            cnt[x.second]=0;
            cout << x.second << " ";
        }
    }
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}