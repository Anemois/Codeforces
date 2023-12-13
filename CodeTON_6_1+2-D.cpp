//2023/12/13 difficulty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n;
    vector<int> vect(n);
    vector<pair<int, int>> best;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        while(!best.empty() && best.back().first >= vect[i])
            best.pop_back();
        best.push_back(make_pair(vect[i], i));
    }
    cin >> k;
    if(k < best[0].first){
        for(int i=0; i<n; i++)
            cout << "0 ";
        cout << "\n";
        return;
    }
    vector<int> ans(n, 0);
    ans[best[0].second] = k/best[0].first;
    int x = k%best[0].first;
    for(int i=0; i<best.size()-1; i++){
        if(x==0) break;
        if(x < 0) cout << "GAWGHOIOEHGOAIHWOIFH\n";
        int can = min(ans[best[i].second], x/(best[i+1].first - best[i].first));
        if(can==0)
            break;
        x -= (best[i+1].first - best[i].first) * can;
        ans[best[i].second] -= can;
        ans[best[i+1].second] += can;
    }
    for(int i=n-2; i>=0; i--)
        ans[i] += ans[i+1];
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}