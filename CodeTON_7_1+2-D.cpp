//2023/11/30 difficulty:1700
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> vect(n+1);
	set<int> st;
	for(int i=1; i<=n; i++){
		cin >> vect[i];
		if(vect[i] == 1)
			st.insert(i);
	}	
	
	for(int t=0; t<q; t++){
		int op;
		cin >> op;
		if(op == 1){
			int x;
			cin >> x;
			//if(!st.empty())
			//	cout << all << " " << max( (n - (*st.begin())+1)*2-st.size(), (*st.rbegin())*2-st.size()) << "\n";
			//else
			//	cout << "empty\n";
			//cout << *st.begin() << " " << *st.rbegin() << "\n";
			if((x%2 == (n*2-st.size())%2 && x<=(n*2-st.size())) || (st.empty() ? false : (x<=max( (n - (*st.begin())+1)*2-st.size(), (*st.rbegin())*2-st.size()))))
				cout << "YES";
			else
				cout << "NO";
			cout << "\n";
		}
		else{
			int i, val;
			cin >> i >> val;
			if(vect[i] == val)
				continue;
			if(val == 1){
				st.insert(i);
			}
				
			else{
				st.erase(i);
			}
			vect[i] = val;
		}
		
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
