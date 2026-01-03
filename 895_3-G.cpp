//2024/1/1 difficulty:2000 https://codeforces.com/contest/1872/problem/G
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#if defined(VOID)
void
#elif defined(INT)
int
#elif defined(BOOL)
bool
#elif defined(STRING)
string
#endif
solve(){
	int n;
	cin >> n;
	vector<int> poi;
	vector<int> prefix(n+1, 0);
	vector<int> vect(n+1, 0);
	for(int i=1; i<=n; i++){
		cin >> prefix[i];
		vect[i] = prefix[i];
		if(prefix[i] != 1)
			poi.push_back(i);
		prefix[i] += prefix[i-1];
	}
	int prod=1, m = poi.size();
	if(m == 0){
		cout << "1 1\n";
		return;
	}
	int MX = 2e14+10;
	for(int i=0; i<m; i++){
		prod *= vect[poi[i]];
		if(prod >= MX || prod < 0){
			cout << poi[0] << " " << poi[m-1] << "\n";
			return;
		}
	}
	//cout << prefix[poi[m-1]] - prefix[poi[0]-1] << " " << prod << " :))))\n";
	int l=1, r=1, mx=0;
	for(int i=0; i<m-1; i++){
		int x = vect[poi[i]];
		for(int j=i+1; j<m; j++){
			x *= vect[poi[j]];
			int plus = x - (prefix[poi[j]] - prefix[poi[i]-1]);
			if(plus > mx){
				mx = plus;
				l = poi[i], r = poi[j];
			}
		}
	}
	cout << l << " " << r << "\n";
}

signed main(){
	Anemoi
	int t=1;
	#if HAS_T == true
	cin >> t;
	#endif
	while(t--){
		#if defined(VOID)
		solve();
		#elif defined(BOOL)
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";
		#else
		cout << solve() << "\n";
		#endif
	}
		
	return 0;
}
/*
int overflow
array bounds special cases (n=1?) 
do smth instead of nothing and stay organized
WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH
you should actually read the stuff at the bottom
*/