//2023/12/19 difficulty:1900
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> vect(n*2);
	int start=-1;
	int mx = -1, index=-1;
	for(int i=0; i<n*2; i++){
		cin >> vect[i].first;
		if(vect[i].first == n*2)
			start = i;
		vect[i].second = index;
		if(vect[i].first > mx){
			mx = vect[i].first;
			index = i;
		}
	}
	vector<vector<int>> dp(n*2+1);
	int last = n*2;
	vector<int> cross;
	// for(auto& i : vect)
	// 	cout << i.first << " " << i.second << "\n";
	{
	int i = start;
	while(i != -1){
		//cout << i << " ";
		cross.push_back(i);
		int len = last - i;
		for(int j=n*2-len; j>=1; j--){
			if(!dp[j].empty() && dp[j+len].empty()){
				dp[j+len] = dp[j];
				dp[j+len].push_back(i);
			}
		}
		dp[len] = {i};
		last = i;
		i = vect[i].second;
	}
	}
	
	if(dp[n].empty())
		cout << -1;
	else{
		// for(auto& i : dp[n])
		// 	cout << i << " ";
		// cout << "\n";
		deque<int> a, b;
		int j = 0;
		int last = n*2;
		auto& v = dp[n];
		for(auto& i : cross){
			//cout << i << " ";
			if(j < v.size() && i == v[j]){
				for(int k=last-1; k>=i; k--){
					a.push_front(vect[k].first);
				}
				j++;
			}
			else{
				for(int k=last-1; k>=i; k--){
					b.push_front(vect[k].first);
				}
			}
			last = i;
		}
		// cout << "\n";
		for(auto& i : a)
			cout << i << " ";
		cout << "\n";
		for(auto& i : b)
			cout << i << " ";
	}
	
}

signed main(){
	int t=1;
	while(t--)
		solve();
	return 0;
}

