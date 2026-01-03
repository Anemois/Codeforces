//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	cin >> n;
	int Asum=0, Bsum=0, Amn=INT_MAX, Bmn=INT_MAX, x;
	for(int i=0; i<n; i++){
		cin >> x;
		Asum += x;
		Amn = min(Amn, x);
	}
	for(int i=0; i<n; i++){
		cin >> x;
		Bsum += x;
		Bmn = min(Bmn, x);
	}
	return min(Asum+(Bmn*n), Bsum + (Amn*n));
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
