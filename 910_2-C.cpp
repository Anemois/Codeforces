#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if(k < n+m-2 || k%2 != (n+m)%2){
    	cout << "NO\n";
		return;	
	}
	cout << "YES\n";
	vector<vector<char>> first(n, vector<char>(m-1, 'R')), second(n-1, vector<char>(m, 'R'));
	
	first[0][0] = 'R';
	first[1][0] = 'R';
	second[0][0] = 'B';
	second[0][1] = 'B';
	bool red = true;
	for(int i=1; i<n-1; i++){
		if(red)
			second[i][0] = 'R';
		else
			second[i][0] = 'B';
		
		red = !red;
	}
	for(int i=0; i<m-1; i++){
		if(red)
			first[n-1][i] = 'R';
		else
			first[n-1][i] = 'B';
		red = !red;	
	}
	red = !red;
	if(red){
		second[n-2][m-1] = 'R';
		second[n-2][m-2] = 'R';
	}
	else{
		second[n-2][m-1] = 'B';
		second[n-2][m-2] = 'B';
	}
		
	red = !red;
	
	if(red)
		first[n-2][m-2] = 'R';
	else
		first[n-2][m-2] = 'B';
		
	red = !red;	
	
	for(auto& i : first){
		for(auto& j : i){
			cout << j << " ";				
		}
		cout << "\n";
	}
	for(auto& i : second){
		for(auto& j : i){
			cout << j << " ";				
		}
		cout << "\n";
	}
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}
