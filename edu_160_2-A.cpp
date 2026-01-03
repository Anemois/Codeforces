//2023/12/27
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
	string str;
	cin >> str;
	int a=str[0]-'0', b=0;
	bool zer = false;
	int n = str.length();
	for(int i=1; i<n; i++){
		if(str[i] != '0')
			zer = true;
		if(zer){
			b *= 10;
			b += str[i]-'0';
		}
		else{
			a *= 10;
			a += str[i]-'0';
		}
	}
	if(a < b)
		cout << a << " " << b;
	else
		cout << -1;
	cout << "\n";
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
