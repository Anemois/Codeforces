#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

bool solve(){
	int n, k;
	cin >> n >> k;
	int x;
	bool ok = false;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x == k)
			ok = true;
	}
	
	return ok;
}

int main()
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
