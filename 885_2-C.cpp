//2023/12/28 difficulty:1800
#include <bits/stdc++.h>

#define HAS_T true
#define BOOL

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int check(int a, int b){
	// bool yes = false;
	// if(a == 3 && b == 5) yes = true;
	if(a == 0 && b == 0)
		return 4;
	int t, cnt=0;
	while(a != 0){
		
		if(a==b){
			cnt+=2;
			break;
		}
		else if(a < b){
			t = b-a;
			cnt++;
			a = b;
			b = t;
		}
		else{
			if(b == 0){
				cnt++;
				break;
			}
			t = a%(b*2);
			a = min(a, t>=b?t:t+b*2);
			if(a%b == 0){
				if(a==b)
					cnt+=2;
				break;
			}
			else{
				t = a-b;
				a = b;
				b = t;
				cnt++;
			}
		}
		// if(yes)
		// 	cout << a << " " << b << "\n";
	}
	// if(yes)
	// 		cout << a << " " << b << "\n";
	return cnt%3;
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
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];
	vector<bool> see(3, false);
	for(int i=0; i<n; i++){
		int x = check(a[i], b[i]);
		if(x == 4)
			continue;
		// cout << x << " ";
		see[x] = true;
		if(x == -1 || see[(x+1)%3] || see[(x+2)%3])
			return false;
	}
	return true;
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
