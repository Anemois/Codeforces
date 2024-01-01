//2024/1/1 difficulty:1500 https://codeforces.com/problemset/problem/1829/G
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MX = 1e6+1;

vector<int> sum(MX, 0);
vector<int> all(MX, 0);

void init(){
	int plus=2;
	int last=3;
	sum[1] = 1;
	all[1] = 1;
	for(int i=2; i<=MX; i++){
		sum[i] = i*i;
		if(i == last - plus + 1){
			all[i] = sum[i] + all[i-plus+1];
		}
		else if(i == last){
			sum[i] += sum[i-plus];
			all[i] = sum[i];
			plus++;
			last += plus;
		}
		else{
			sum[i] += sum[i-plus];
			all[i] = sum[i] + all[i-plus+1];
		}
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
	int n;
	cin >> n;
	return all[n];
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
/*
int overflow
array bounds special cases (n=1?) 
do smth instead of nothing and stay organized
WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH
you should actually read the stuff at the bottom
*/