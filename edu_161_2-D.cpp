#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
	int atk, def, l, r, next;
	P(int a, int b, int c, int d, int e){
		atk=a;def=b;l=c;r=d;next=e;
	}
	P(){
		;
	}
};

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
	int n;
	cin >> n;
	vector<P> vect(n+2);
	for(int i=1; i<=n; i++)
		cin >> vect[i].atk;
	for(int i=1; i<=n; i++){
		vect[i].l = i-1;
		vect[i].next = i-1;
		vect[i].r = i+1;
		cin >> vect[i].def;
	}
	vect[0] = P(0, INT_MAX, -1, 1, -1);
	vect[n+1] = P(0, INT_MAX, n, n+2, n);
	vector<int> pend1, pend2;
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(vect[i].def < vect[vect[i].l].atk + vect[vect[i].r].atk){
			cnt++;
			if(!pend1.empty() && pend1.back() == i)
				pend1.pop_back();
			if((pend1.empty() || pend1.back() != vect[i].next) && vect[i].next >= 1)
				pend1.push_back(vect[i].next);
			if(vect[i].r <= n)
				pend1.push_back(vect[i].r);

			vect[vect[i].next].r = vect[i].r;
			vect[vect[i].r].next = vect[i].next;
		}
		vect[i].l = vect[i].next;
	}
	// for(auto i : pend1)
	// 	cout << i << " ";
	// cout << ":";
	cout << cnt << " ";
	for(int T=1; T<n; T++){
		pend2.clear();
		// for(int i=1; i<=n; i++){
		// 	cout << i << " " << vect[i].l << " " << vect[i].r << " " << vect[i].next << "\n";
		// }
		cnt=0;
		int N = pend1.size();
		for(int j=0; j<N; j++){
			auto& i = pend1[j];
			//cout << i << " ";
			//cout << vect[i].l << " " << vect[i].r << "\n";
			if(vect[i].def < vect[vect[i].l].atk + vect[vect[i].r].atk){
				cnt++;
				if(!pend2.empty() && pend2.back() == i)
					pend2.pop_back();
				if((pend2.empty() || pend2.back() != vect[i].next) && vect[i].next >= 1)
					pend2.push_back(vect[i].next);
				if(vect[i].r <= n)
					pend2.push_back(vect[i].r);
				vect[vect[i].next].r = vect[i].r;
				vect[vect[i].r].next = vect[i].next;
				if((j != N-1 && pend1[j+1] != vect[i].r) || j==N-1)
					vect[vect[i].r].l = vect[vect[i].r].next;
			}
			vect[i].l = vect[i].next;
		}
		// for(auto i : pend2)
		// 	cout << i << " ";
		// cout << ":";
		cout << cnt << " ";
		swap(pend1, pend2);
	}
	cout << "\n";
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
/*
int overflow
array bounds special cases (n=1?) 
do smth instead of nothing and stay organized
WRITE STUFF DOWN DON'T GET STUCK ON ONE APPROACH
you should actually read the stuff at the bottom
*/