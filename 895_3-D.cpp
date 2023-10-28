//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int solve(){
    int n, x, y;
    cin >> n >> x >> y;
    int red = n/x, blue = n/y, purple = n/((x*y)/__gcd(x, y));
    red -= purple; blue -= purple;
    return (n*(n+1)/2) - ((n-red)*(n-red+1)/2) - (blue*(blue+1)/2);
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
