//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int l, r;
};

vector<P> vect(200010);
int n;

bool check(int x){
    int l=0, r=0;
    for(int i=0; i<n; i++){
        l-=x;
        r+=x;
        if(vect[i].l > r || vect[i].r < l){
            return false;
        }
        l = max(l, vect[i].l);
        r = min(r, vect[i].r);
    }
    return true;
}

void solve(){
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> vect[i].l >> vect[i].r;
    
    int l=0, r=1000000000;
    while(l<r){
        int m = (l+r)/2;
        if(check(m))
            r = m;
        else
            l = m+1;
    }
    cout << l << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}