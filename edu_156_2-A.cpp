//2023/11/18 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n <= 6)
        cout << "NO";
    else if(n%3 == 0){
        if(n<=9)
            cout << "NO";
        else
            cout << "YES\n" << "1 4 " << n-5;
    }
    else
        cout << "YES\n" << "1 2 " << n-3;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
        cout << "\n";
    }
    return 0;
}