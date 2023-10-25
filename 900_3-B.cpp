#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	int a=2, b=3, c;
	cout << 2 << " " << 3 << " ";
	for(int i=2; i<n; i++){
		c = b+1;
		while((c*3)%(a+b) == 0)
			c++;
		cout << c << " ";
		a = b;
		b = c;
	}
	cout << "\n";
}

signed main()
{	
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		solve();
	
	return 0;
}
