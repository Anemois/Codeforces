//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
 
int solve(){
	int n;
	cin >> n;
	int W, C;
	cin >> W >> C;
	int a, b;
	bool ok = true;
	for(int i=1; i<n; i++){
		cin >> a >> b;
		if(a >= W && b >= C)
			ok = false;
	} 
	if(ok)
		return W;
	else
		return -1;
}
 
signed main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cout << solve() << "\n";
	return 0;
}