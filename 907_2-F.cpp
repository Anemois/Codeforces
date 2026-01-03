//2024/1/1 difficulty:2000 https://codeforces.com/problemset/problem/1891/F
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MX = 500010;

struct P2{
	int val, tm;
	P2(int x, int t){
		val = x;
		tm = t;
	}
};

struct P{
	vector<int> to;
	vector<P2> add;
	void clear(){
		to.clear();
		add.clear();
	}
};

vector<P> graph(MX);
vector<int> fenwick(MX);
vector<int> ans(MX);
int FINAL;

void update(int p, int x){
	for(;p<MX; p+=p&(-p))
		fenwick[p] += x;
}

int query(int p){
	int sum=0;
	for(;p>0; p-=p&(-p))
		sum += fenwick[p];
	return sum;
}

void go(int p){
	for(auto& i : graph[p].add){
		update(1, i.val);
		update(i.tm+1, -i.val);
	}
	// for(int i=1; i<=FINAL; i++){
	// 	cout << query(i) << " ";
	// }
	// cout << "\n";
	ans[p] = query(p);
	for(auto& i : graph[p].to){
		go(i);
	}
	for(auto& i : graph[p].add){
		update(1, -i.val);
		update(i.tm+1, i.val);
	}
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
	int n, tm=1;
	cin >> n;
	graph[1].clear();
	for(int i=1; i<=n; i++){
		int op;
		cin >> op;
		if(op == 1){
			int v;
			cin >> v;
			tm++;
			graph[tm].clear();
			graph[v].to.push_back(tm);
		}
		else{
			int v, x;
			cin >> v >> x;
			graph[v].add.push_back(P2(x, tm));
		}
	}
	FINAL = tm;
	fill(fenwick.begin(), fenwick.begin()+FINAL+3, 0);
	go(1);
	for(int i=1; i<=FINAL; i++)
		cout << ans[i] << " ";
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
