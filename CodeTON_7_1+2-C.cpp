//2023/11/30 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	int i, val;
};

void solve(){
	int n, x;
	cin >> n >> x;
	vector<P> a(n), b(n);
	for(int i=0; i<n; i++){
		cin >> a[i].val;
		a[i].i = i;
	}
	for(int i=0; i<n; i++){
		cin >> b[i].val;
		b[i].i = i;
	}

	sort(a.begin(), a.end(), [](const P& c, const P& d){
		return c.val > d.val;
	});
	sort(b.begin(), b.end(), [](const P& c, const P& d){
		return c.val < d.val;
	});
	reverse(b.begin(), b.begin()+x);
	reverse(b.begin()+x, b.end());
	// for(auto& i : b)
	// 	cout << i.val << " ";
	// cout << "\n";
	int j=0;
	bool can = true;
	for(int i=0; i<x; i++){
		if(b[i].val >= a[i].val){
			can = false;
			break;
		}
			
	}
	for(int i=x; i<n; i++){
		if(b[i].val < a[i].val){
			can = false;
			break;
		}
			
	}
	if(can){
		cout << "YES\n";
		for(int i=0; i<n; i++){
			b[i].i = a[i].i;
		}
		sort(b.begin(), b.end(), [](const P& c, const P& d){
			return c.i < d.i;
		});
		for(auto& i : b)
			cout << i.val << " ";
		cout << "\n";
	}
	else{
		cout << "NO\n";
	}
}

signed main(){
	Anemoi
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
		solve();
	return 0;
}
