//2023/12/31 difficulty:2500 https://codeforces.com/problemset/problem/1917/E
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
	int n, k;
	cin >> n >> k;
	if(k == 2 || k == n*n-2){
		if(n == 2){
			cout << "Yes\n";
			cout << "1 0 \n";
			cout << "0 1 \n";
		}
		else{
			cout << "No\n";
		}
	}
	else if(k%4==0){
		cout << "Yes\n";
		int x = k/4;
		for(int i=0; i<n; i+=2){
			int now = max(min(x, n/2), 0LL);
			for(int j=0; j<now; j++)
				cout << "1 1 ";
			for(int j=now; j<n/2; j++)
				cout << "0 0 ";
			cout << "\n";
			for(int j=0; j<now; j++)
				cout << "1 1 ";
			for(int j=now; j<n/2; j++)
				cout << "0 0 ";
			cout << "\n";
			x -= n/2;
		}
	}
	else if(k%4 == 2){
		cout << "Yes\n";
		vector<vector<bool>> mat(n, vector<bool>(n, 0));
		mat[0][0] = 1;
		mat[0][1] = 1;
		mat[1][0] = 1;
		mat[1][2] = 1;
		mat[2][1] = 1;
		mat[2][2] = 1;
		if(k==n*n-6){
			k-=4;
			mat[0][2] = 1;
			mat[0][3] = 1;
			mat[3][2] = 1;
			mat[3][3] = 1;
		}
		int x = (k-6)/4;
		for(int j=4; j<n; j+=2){
			if(x-- <= 0)
				break;
			mat[0][j]=1;
			mat[0][j+1]=1;
			mat[1][j]=1;
			mat[1][j+1]=1;
		}
		for(int j=4; j<n; j+=2){
			if(x-- <= 0)
				break;
			mat[2][j]=1;
			mat[2][j+1]=1;
			mat[3][j]=1;
			mat[3][j+1]=1;
		}
		for(int i=4; i<n; i+=2){
			for(int j=0; j<n; j+=2){
				if(x-- <= 0)
					break;
				mat[i][j]=1;
				mat[i][j+1]=1;
				mat[i+1][j]=1;
				mat[i+1][j+1]=1;
			}
		}
		for(auto& i : mat){
			for(auto j : i)
				cout << j << " ";
			cout << "\n";
		}
	}
	else
		cout << "No\n";
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
