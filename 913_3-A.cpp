//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    string str;
    cin >> str;
    for(int i=1; i<=8; i++){
        if(i != str[1]-'0'){
            cout << str[0] << i << "\n";
        }
    }
    for(int i=0; i<8; i++){
        if(i != str[0]-'a'){
            char x = i+'a';
            cout << x << str[1] << "\n";
        }
    }
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}