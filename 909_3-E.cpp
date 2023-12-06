//2023/12/6 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
	int n;
	cin >> n;
	vector<int> vect(n);
	for(int i=0; i<n; i++)
		cin >> vect[i];
	int j = -1;
	for(int i=n-2; i>=0; i--){
		if(j != -1){
			if(vect[i] <= vect[j+1])
				return -1;
		}
		else if(vect[i] > vect[i+1]){
			j = i;
		}
	}
	return j+1;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}

