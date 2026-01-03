//2023/12/3
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    if(str.length() == 1){
        return str[0] == '0';
    }
    bool zero = false;
    for(int i=0; i<n-1; i++){
        if(str[i] != str[i+1])
            return true;
        if(str[i] == '0')
            zero = true;
    }

    return zero;
}
signed main(){
    Anemoi
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
}