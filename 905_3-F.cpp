//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#pragma GCC optimize("O2")
using namespace std;
 
int solve(){
	int n;
	cin >> n;
	vector<int> vect(1), suffix(1, 0);
	int x;
	set<int> sl;
	cin >> vect[0];
	sl.insert(vect[0]);
	suffix[0] = 1;
	for(int i=1; i<n; i++){
		cin >> x;
		vect.emplace_back(x);
		suffix.emplace_back(0);
		if(sl.find(vect[i]) == sl.end()){
			sl.insert(vect[i]);
			suffix[i]++;
		}
		
		suffix[i] += suffix[i-1];
	}
	sl.clear();
	int cnt = 0;
	for(int i=n-1; i>=0; i--)
		if(sl.find(vect[i]) == sl.end()){
			sl.insert(vect[i]);
			cnt += suffix[i];
		}
	return cnt;
			
}
 
signed main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cout << solve() << "\n";
	return 0;
}