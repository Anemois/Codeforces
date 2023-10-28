//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
	int n, k, x;
	cin >> n >> k >> x;
	//cout << k*(k+1)/2 << " " << x << " " << (n*(n+1)/2) - ((n-k)*(n-k+1)/2) << " ";
	return (x >= k*(k+1)/2 && x <= (n*(n+1)/2) - ((n-k)*(n-k+1)/2));
}

signed main()
{	
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	
	return 0;
}
