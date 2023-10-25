#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int solve(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	int mn = INT_MAX;
	int one_cnt = 0, two = 0;
	for(auto& i : v){
		if(i%2 == 1) one_cnt++;
		if(i%2 == 0) two++;
		mn = min(mn, (k - i % k)%k);
	}
	if(k == 4 && two >= 2) return 0;
	if(k == 4 && two == 1 && one_cnt >= 1) return min(mn, 1);
	if(k == 4 && one_cnt >= 2) return min(mn, 2);
	return mn;
}

int main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << solve() << "\n";
	}
	return 0;
}
