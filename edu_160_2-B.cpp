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
	string str;
	cin >> str;
	int n = str.length();
	int zero=0, one=0;
	for(auto& c : str){
		if(c=='0')
			zero++;
		else
			one++;
	}
	for(int i=0; i<n; i++){
		if(one==0 || zero==0){
			if((one == 0 && str[i] == '0') || (zero == 0 && str[i] == '1'))
				return n-i;
		}
		else if(str[i] == '0'){
			one--;
		}
		else if(str[i] == '1'){
			zero--;
		}
	}

	return 0;
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
