//2023/12/17
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
	
	deque<pair<int, int>> dq;
	int ans, sum=0;
	int MEX = vect.back();
	for(int i=n-2; i>=0; i--){
		dq.push_front(make_pair(MEX, 1));
		sum += MEX;
		MEX = min(MEX, vect[i]);	
	}
	dq.push_front(make_pair(MEX, 1));
	sum += MEX + n;
	ans = sum;
	//for(auto& i : dq)
	//	cout << i.first << " " << i.second << " - ";
	//cout << "\n";
	for(int i=0; i<n; i++){
		pair<int, int> now = make_pair(vect[i], 1);
		sum -= dq.front().first;
		if(--dq.front().second == 0)
			dq.pop_front();
		while(!dq.empty() && dq.back().first >= now.first){
			sum -= dq.back().first * dq.back().second;
			now.second += dq.back().second;
			dq.pop_back();
		}
		sum += now.first * now.second;
		dq.push_back(now);
		ans = max(ans, sum);
	}
	return ans;
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	while(t--)
		cout << solve() << "\n";
	return 0;
}
