//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long

using namespace std;

struct P{
    int val, p;
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<P> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].val;
        vect[i].p = i+1;
        vect[i].val = vect[i].val % k;
        if(vect[i].val == 0) vect[i].val += k;
    }
    sort(vect.begin(), vect.end(), [&](const P& a, const P& b){
        if(a.val == b.val){
            return a.p < b.p;
        }
        return a.val > b.val;
    });
    for(int i=0; i<n; i++){
        cout << vect[i].p << " ";
    }
    cout << "\n";
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}