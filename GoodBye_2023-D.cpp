//2023/12/30 https://codeforces.com/contest/1916/problem/D
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<vector<string>> ans(100);

string tim(int x){
	string str;
	for(int i=0; i<x; i++)
		str += "0";
	return str;
}

void init(){
	ans[1] = {"1"};
	ans[3] = {"169",
			  "196",
			  "961"};
	for(int i=5; i<=99; i+=2){
		for(auto& j : ans[i-2]){
			ans[i].push_back(j + "00");
		}
		ans[i].push_back("1" + tim((i-3)/2) + "6" + tim((i-3)/2) + "9");
		ans[i].push_back("9" + tim((i-3)/2) + "6" + tim((i-3)/2) + "1");
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
	for(auto& i : ans[n])
		cout << i << "\n";	
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
