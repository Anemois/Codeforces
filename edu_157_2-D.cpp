//2023/12/28 difficulty:1900
#include <bits/stdc++.h>

#define HAS_T false
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	vector<P*> ok;
	P(){
		ok.resize(2, nullptr);
	}
};

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
	vector<int> vect(n);
	P* root = new P();
	vect[0] = 0;
	for(int i=1; i<n; i++){
		cin >> vect[i];
		vect[i] ^= vect[i-1];
		P* ptr = root;
		for(int j=20; j>=0; j--){
			if((vect[i]>>j)&1){
				if(ptr->ok[1] == nullptr)
					ptr->ok[1] = new P();
				ptr = ptr->ok[1];
			}
			else{
				if(ptr->ok[0] == nullptr)
					ptr->ok[0] = new P();
				ptr = ptr->ok[0];
			}
		}
	}
	for(int i=0; i<n; i++){
		int now=0;
		P* ptr = root;
		for(int j=20; j>=0; j--){
			if(ptr->ok[0] == nullptr && ptr->ok[1] == nullptr)
				break;
			if((i>>j)&1){
				if(ptr->ok[0] != nullptr){
					now += (1<<j);
					ptr = ptr->ok[0];
				}
				else{
					ptr = ptr->ok[1];
				}
			}
			else{
				if(ptr->ok[1] != nullptr){
					now += (1<<j);
					ptr = ptr->ok[1];
				}
				else{
					ptr = ptr->ok[0];
				}
			}
		}
		if(now < n){
			cout << i << " ";
			for(int j=1; j<n; j++)
				cout << (i^vect[j]) << " ";
			return;
		}
	}
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
