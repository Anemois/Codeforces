//2023/11/26
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;


void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    bool A = false, B = false, C = false;
    if((b+c)%2 == 0)
        A = true;
    if((a+c)%2==0)
        B = true;
    if((a+b)%2==0)
        C = true;
    if(A)
        cout << "1 ";
    else
        cout << "0 ";
    if(B)
        cout << "1 ";
    else
        cout << "0 ";
    if(C)
        cout << "1\n";
    else
        cout << "0\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}