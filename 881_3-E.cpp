//2023/12/26 difficulty:1600
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int n, m;
vector<int> vect(1e5+10);

struct P{
	int l, r;
};

bool check(vector<P>& segs, vector<int>& query, int x){
	fill(vect.begin()+1, vect.begin()+n+1, 0);
	for(int i=1; i<=x; i++)
		vect[query[i]]++;
	for(int i=1; i<=n; i++){
		vect[i] += vect[i-1];
		//cout << vect[i] << " ";
	}
	//cout << "\n";
	for(auto& i : segs){
		if(vect[i.r] - vect[i.l-1] >= (i.r-i.l+1)/2+1)
			return true;
	}
	return false;
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
	cin >> n >> m;
	vector<P> segs(m);
	for(int i=0; i<m; i++){
		cin >> segs[i].l >> segs[i].r;
	}
	int q;
	cin >> q;
	vector<int> query(q+1);
	for(int i=1; i<=q; i++)
		cin >> query[i];
	int l=1, r=q+1;
	while(l < r){
		int m = (l+r)/2;
		//cout << m << "\n";
		if(check(segs, query, m))
			r = m;
		else
			l = m+1;
	}
	return l==q+1?-1:l;
}

signed main(){
	Anemoi
	vect[0] = 0;
	int t;
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
