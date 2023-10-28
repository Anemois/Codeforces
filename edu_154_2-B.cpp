//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
	string a, b;
	cin >> a >> b;
	int n = a.length();
	for(int i=0; i<n-1; i++){
		if(a[i] == '0' && b[i] == '0' && a[i+1] == '1' && b[i+1] == '1')
			return true;
	}
	return false;
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
