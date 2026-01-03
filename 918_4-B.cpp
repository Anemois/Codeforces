//2023/12/28
#include <bits/stdc++.h>

#define HAS_T true
#define STRING

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
	vector<string> vect(3);
	string ans;
	for(int i=0; i<3; i++){
		cin >> vect[i];
		vector<bool> yes(3, false);
		for(auto& c : vect[i]){
			if(c == 'A')
				yes[0] = true;
			if(c == 'B')
				yes[1] = true;
			if(c == 'C')
				yes[2] = true;
		}
		if(!yes[0]){
			ans = "A";
		}
		if(!yes[1])
			ans = "B";
		if(!yes[2])
			ans = "C";
	}
	return ans;
		
	
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
