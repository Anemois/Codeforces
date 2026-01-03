//2023/12/24
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    int neg=0;
    bool zero = false;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        if(vect[i] < 0)
            neg++;
        else if(vect[i] == 0)
            zero = true;
    }
    if(zero || neg%2 == 1)
        cout << 0 << "\n";
    else{
        cout << "1\n";
        cout << "1 0\n";
    }
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}