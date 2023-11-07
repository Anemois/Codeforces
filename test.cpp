#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

signed main(){
    int cnt=2;
    int a = 0, b = 1;
    while(b <= 200000){
        int c = a+b;
        a = b;
        b = c;
        cnt++;
    }

    cout << cnt;
}