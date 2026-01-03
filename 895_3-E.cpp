//2023/12/10 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n+1), prefix(n+1);
    vect[0]=0, prefix[0] = 0;
    int all, one=0;
    for(int i=1; i<=n; i++){
        cin >> vect[i];
        prefix[i] = prefix[i-1] ^ vect[i];
    }
    string str;
    cin >> str;
    all = prefix[n];
    for(int i=1; i<=n; i++){
        if(str[i-1] == '1')
            one ^= vect[i];
    }
    int q;
    cin >> q;
    while(q--){
        int opr;
        cin >> opr;
        if(opr == 1){
            int l, r;
            cin >> l >> r;
            //cout << "--- " << (all ^ prefix[l-1] ^ (all ^ prefix[r])) << " " << test << " --- ";
            one ^= all ^ prefix[l-1] ^ (all ^ prefix[r]);
        }
        else{
            int o;
            cin >> o;
            if(o == 0)
                cout << (all ^ one) << " ";
            else
                cout << one << " ";
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