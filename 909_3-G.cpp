//2023/12/28 difficulty:1900
#include <bits/stdc++.h>

#define HAS_T true
#define VOID

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;
const int MX = 1e5+10;
vector<vector<int>> graph(MX);
vector<int> tin(MX), tout(MX);

int TIM = 0;

struct SegmentTree{
    vector<vector<int>> tree;
    int n;
    void build(vector<int>& a, int l, int r, int p){
        if(l == r)
            tree[p].push_back(a[l]);
        else{
            int m = (l+r)/2;
            build(a, l, m, p*2);
            build(a, m+1, r, p*2+1);
            merge(tree[p*2].begin(), tree[p*2].end(), tree[p*2+1].begin(), tree[p*2+1].end(), back_inserter(tree[p]));
        }
    }

    SegmentTree(vector<int>& a){
        n = a.size();
        tree.resize(n*4);
        build(a, 1, n, 1);
    }

    bool query(int& l, int& r, int L, int R, int p, int& mn, int& mx){
        if(l <= L && R <= r){
            return lower_bound(tree[p].begin(), tree[p].end(), mx) - lower_bound(tree[p].begin(), tree[p].end(), mn) > 0;
        }
        else{
            int M = (L+R)/2;
            if(r <= M)
                return query(l, r, L, M, p*2, mn, mx);
            else if(l > M)
                return query(l, r, M+1, R, p*2+1, mn, mx);
            else
                return query(l, r, L, M, p*2, mn, mx) || query(l, r, M+1, R, p*2+1, mn, mx);
        }
    }

    bool query(int l, int r, int mn, int mx){
        return query(l, r, 1, n, 1, mn, mx);
    }
};

void dfs(int last, int p){
    tin[p] = TIM++;
    for(auto& i : graph[p]){
        if(i != last){
            dfs(p, i);
        }
    }
    tout[p] = TIM;
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
	int n, q;
    cin >> n >> q;
    TIM=0;
    for(int i=1; i<=n; i++){
        graph[i].clear();
    }
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(-1, 1);
    vector<int>  a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] = tin[a[i]];
    }
    SegmentTree sg(a);

    for(int i=0; i<q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        if(sg.query(l, r, tin[x], tout[x]))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
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
