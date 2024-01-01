//2023/12/31 difficulty:1900 https://codeforces.com/problemset/problem/1882/D
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
const int MAX = 2e5+10;

struct P{
	int p, cnt;
	P(int x){
		p = x;
		cnt=-1;
	}
};

struct NODE{
	int val;
	vector<P> to;
};

int n;
vector<NODE> graph(MAX);

bool same(int& a, int& b, int& bit){
	return ((a>>bit)&1) == ((b>>bit)&1);
}

int runfirst(int now, int from, int& bit){
	int sum=0;
	for(auto& i : graph[now].to){
		if(i.p == from)
			continue;
		sum += runfirst(i.p, now, bit);
		if(!same(graph[now].val, graph[i.p].val, bit))
			sum += i.cnt * (1LL<<bit);
	}
	return sum;
}

void runsecond(vector<vector<int>>& ans, int now, int from, int bit){
	if(same(graph[now].val, graph[from].val, bit))
		ans[now][bit] = ans[from][bit];
	else{
		int sum=0;
		int parcnt=0;
		for(auto& i : graph[now].to){
			if(i.p == from)
				parcnt = i.cnt;
			else
				sum += i.cnt;
		}
		ans[now][bit] = ans[from][bit] + ((parcnt-sum-1)*(1LL<<bit));
	}
	for(auto& i : graph[now].to){
		if(i.p != from){
			runsecond(ans, i.p, now, bit);
		}
	}
}

int getcnt(int now, int from){
	int sum=1;
	int parent=-1;
	int nn = graph[now].to.size();
	for(int j=0; j<nn; j++){
		P& i = graph[now].to[j];
		if(i.p == from){
			parent = j;
			continue;
		}
		i.cnt = getcnt(i.p, now);
		sum += i.cnt;
	}
	graph[now].to[parent].cnt = n-sum;
	return sum;
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
	cin >> n;
	
	for(int i=1; i<=n; i++){
		graph[i].to.clear();
		cin >> graph[i].val;
	}
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		graph[u].to.push_back(P(v));
		graph[v].to.push_back(P(u));
	}
	for(auto& i : graph[1].to){
		i.cnt = getcnt(i.p, 1);
	}
	vector<vector<int>> ans(n+1, vector<int>(21, 0));
	for(int i=0; i<=20; i++){
		ans[1][i] = runfirst(1, -1, i);
		for(auto& j : graph[1].to){
			runsecond(ans, j.p, 1, i);
		}
	}
	for(int i=1; i<=n; i++){
		int sum=0;
		for(int j=0; j<=20; j++){
			sum += ans[i][j];
		}
		cout << sum << " ";
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
