//2023/12/25
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    int cnt=0;
    while(n--){
        int x;
        cin >> x;
        if(x&1)
            cnt++;
    }
    return cnt%2==0;
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