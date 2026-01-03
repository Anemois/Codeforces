//2023/12/16 difficlty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#define l first
#define r second

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> vect(n);
    for(int i=0; i<n; i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        vect[i] = make_pair(l, b);
    }
    sort(vect.begin(), vect.end());
    int l=vect[0].l, r=vect[0].r;
    vector<pair<int, int>> best = {make_pair(0, 0)};
    for(int i=1; i<n; i++){
        if(r >= vect[i].l)
            r = max(r, vect[i].r);
        else{
            best.push_back(make_pair(l, r));
            l=vect[i].l, r=vect[i].r;
        }
    }
    best.push_back(make_pair(l, r));
    // for(auto& i : best)
    //     cout << i.l << " " << i.r << " - ";
    // cout << "\n";
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        auto p = lower_bound(best.begin(), best.end(), make_pair(x+1, -1LL));
        p--;
        cout << max((*p).r, x) << " ";
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