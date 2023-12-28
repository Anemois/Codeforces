//2023/12/27
#include <bits/stdc++.h>

#define HAS_T true
#define INT

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
	int mx = 0;
	cin >> n;
	vector<int> vect(n);
	for(int i=0; i<n; i++){
		cin >> vect[i];
		mx = max(mx, vect[i]);
	}
	vector<int> cnt(mx+1, 0), divs(mx+1, 0);
	sort(vect.begin(), vect.end());
	for(int i=0; i<n; i++){
		int N = sqrt(vect[i]);
		for(int j=1; j<=N; j++){
			if(vect[i]%j == 0){
				cnt[j] += (divs[j]++) * (n-i-1);
				if(j*j != vect[i])
					cnt[vect[i]/j] += (divs[vect[i]/j]++) * (n-i-1);
			}
		}
	}
	int ans=0;
	for(int i=mx; i>=1; i--){
		for(int j=i*2; j<=mx; j+=i)
			cnt[i] -= cnt[j];
		ans += cnt[i]*i;
	}
	return ans;
}

signed main(){
	Anemoi
	int t;
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
