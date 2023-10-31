//2023/10/30
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

bool solve(){
    int n;
    cin >> n;
    int last = 0, x, two = 1;
    bool can = true;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(i == two+1){
            two *= 2;
        }
        else if(last > x){
            can = false;
        }
        //cout << i << " " << two << " " << x << " " << last << "\n";
        last = x;
    }
    return can;
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
	return 0;
}
