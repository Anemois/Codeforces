//2023/12/5
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	int x, y;
	
	bool operator<(const P& other) const{
		if(x == other.x)
			return y < other.y;
		return x < other.x;
	}
};

string str;
map<P, vector<int>> mp;
vector<P> vect;
int n, q;

bool check(int x, int y, int l, int r){
	P temp = {x, y};
	if(l > r || mp.find(temp) == mp.end())
		return false;
		
	auto ptr = lower_bound(mp[temp].begin(), mp[temp].end(), l);
	return ptr != mp[temp].end() && *ptr <= r;
}

bool solve(){
	int x, y, l, r;
	cin >> x >> y >> l >> r;
	return 	check(x, y, 0, l-1) ||
			check(x, y, r, n)   ||
			check(vect[l-1].x+vect[r].x-x, vect[l-1].y+vect[r].y-y, l, r-1);
}

signed main(){
	Anemoi
	cin >> n >> q;
	cin >> str;
	vect.resize(n+1);
	vect[0] = {0, 0};
	mp[vect[0]].push_back(0);
	for(int i=0; i<n; i++){
		vect[i+1].x = vect[i].x + (str[i]=='R') - (str[i]=='L');
		vect[i+1].y = vect[i].y + (str[i]=='U') - (str[i]=='D');
		mp[vect[i+1]].push_back(i+1);
	}
	for(int t=0; t<q; t++){
		if(solve())
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";	
	}
	return 0;
}
