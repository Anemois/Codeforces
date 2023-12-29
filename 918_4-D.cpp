//2023/12/28
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool isv(char c){
	return c == 'a' || c == 'e';
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
	string str;
	cin >> str;
	vector<string> ans;
	for(int i=n-1; i>=0; i--){
		if(isv(str[i])){
			ans.push_back(str.substr(i-1, 2));
			i--;
		}
		else{
			ans.push_back(str.substr(i-2, 3));
			i-=2;
		}
	}
	for(int i=ans.size()-1; i>=0; i--){
		cout << ans[i];
		if(i != 0)
			cout << ".";
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
