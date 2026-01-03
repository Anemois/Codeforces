//2023/12/17 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
	int n;
	cin >> n;
	return n%3==0;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		if(solve())
			cout << "Second\n";
		else
			cout << "First\n";
	return 0;
}