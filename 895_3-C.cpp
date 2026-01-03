//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int min_div(int x){
    for(int i=2; i<=sqrt(x)+1; i++){
        if(x % i == 0)
            return i;
    }
    return x;
}

void solve(){
    int l, r;
    cin >> l >> r;
    for(int i=l; i<=r; i++){
        int md = min_div(i);
        if(md != i){
            cout << md << " " << i-md << "\n";
            return;
        }
    }
    cout << "-1\n";
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve();
    }
	return 0;
}
