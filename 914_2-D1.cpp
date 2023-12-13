//2023/12/13
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    for(int i=0; i<n; i++){
        bool ltr=true, rtl=true;
        for(int j=i; j>=0; j--){
            if(b[i] == a[j]){
                ltr=false;
                break;
            }
            if(b[i] < a[j] || b[i] > b[j])
                break;
        }
        for(int j=i; j<n; j++){
            if(b[i] == a[j]){
                rtl=false;
                break;
            }
            if(b[i] < a[j] || b[i] > b[j])
                break;
        }
        if(ltr&&rtl)
            return false;
    }
    return true;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
}