//2023/12/30 difficulty:1900 https://codeforces.com/problemset/problem/1878/F
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<int> primes(1000010, -1);
void init(){
	int n = sqrt(1000010);
	for(int i=2; i<=n; i++){
		if(primes[i] == -1){
			primes[i] = i;
			for(int j=i*i; j<1000010; j+=i){
				primes[j] = i;
			}
		}
	}
	for(int i=n; i<1000010; i++){
		if(primes[i] == -1)
			primes[i] = i;
	}
}

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
	unordered_map<int, int> mp;
	while(n > 1){
		mp[primes[n]]++;
		n /= primes[n];
	}
	//cout << n << " " << base << "\n";
	unordered_map<int, int> now = mp;
	
	while(q--){
		int op;
		cin >> op;
		if(op==2){
			now = mp;
			continue;
		}
		int y;
		cin >> y;
		while(y>1){
			now[primes[y]]++;
			y /= primes[y];
		}
		//cout << cnt << " " << z << "\n";
		unordered_map<int, int> cc;
		for(const auto& i : now){
			int x = i.second+1;
			//cout << i.first << " " << i.second << "\n";
			while(x > 1){
				cc[primes[x]]++;
				x /= primes[x];
			}
		}
		bool can = true;
		for(const auto& i : cc){
			//cout << i.first << " " << now[i.first] << " -- " << i.second << "\n";
			if(now[i.first] < i.second){
				can = false;
			}
		}
		if(can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	cout << "\n";
}

signed main(){
	Anemoi
	init();
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
