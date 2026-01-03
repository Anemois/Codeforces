//2023/11/26
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int cnt = 0;
    int n;
    cin >> n;
    string str;
    cin >> str;
    for(int i=0; i<n; i++){
        if(i+2 < n && str[i] == '.' && str[i+1] == '.' && str[i+2] == '.')
            return 2;
        if(str[i] == '.')
            cnt++;
    }
    return cnt;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}