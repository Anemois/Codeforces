//2023/12/10 difficulty:1500
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    string str;
    cin >> str;
    int n = str.length(), all=0, mn=INT_MAX, cnt=0;
    for(int i=0; i<n; i++){
        if(str[i] == 'A'){
            all++;
            cnt++;
        }
        if(str[i] == 'B'){
            mn = min(mn, cnt);
            cnt = 0;
        }
    }
    mn = min(mn, cnt);
    return max(0LL, all-mn);
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}