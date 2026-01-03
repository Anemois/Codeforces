//2024/1/26 difficulty:1900
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
	int n, q;
	cin >> n >> q;
	vector<int> vect(n+1, 0);
	for(int i=1; i<=n; i++)
		cin >> vect[i];
	int lim=sqrt(n)+1;
	vector<vector<int>> prefix(lim, vector<int>(n+1, 0));
	vector<vector<int>> times(lim, vector<int>(n+1, 0));
	for(int i=1; i<lim; i++){
		for(int j=1; j<=i; j++){
			times[i][j] = prefix[i][j] = vect[j];
			for(int k=j+i, t=2; k<=n; k+=i, t++){
				times[i][k] = vect[k]*t + times[i][k-i];
				prefix[i][k] = vect[k] + prefix[i][k-i];
			}
		}
	}

	while(q--){
		int s, d, k, e;
		cin >> s >> d >> k;
		e = s+d*(k-1);
		if(d < lim){
			int ml = (s+d-1)/d -1;
			cout << times[d][e] - (ml*prefix[d][e]) + (s>d ? (ml*prefix[d][s-d])-times[d][s-d] : 0);
		}
		else{
			int ans=0;
			for(int i=1; i<=k; i++){
				ans += vect[s+d*(i-1)]*i;
			}
			cout << ans;
		}
		cout << " ";
	}
	cout << "\n";
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