//2023/12/23
#include<bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    bool xn=false, xp=false, yp=false, yn=false;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        if(x > 0)
            xp = true;
        if(x < 0)
            xn = true;
        if(y > 0)
            yp = true;
        if(y < 0)
            yn = true;
    }
    return !(xn&&xp&&yp&&yn);
}

signed main(){
    Anemoi
    int t=1;
    cin >> t;
    while(t--)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}