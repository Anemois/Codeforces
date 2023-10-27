#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int solve(){
    int n;
    cin >> n;
    int mn = INT_MAX, a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        mn = min(mn, a+(b-1)/2);
    }
    return mn;
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << solve() << "\n";
    }
	return 0;
}
