//2023/12/28
#include <bits/stdc++.h>

#define HAS_T true
#define INT

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

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
			//sort(tree[p].begin(), tree[p].end());
        }
    }

    SegmentTree(vector<int>& a){
        n = a.size()-1;
        tree.resize(n*4);
        build(a, 1, n, 1);
    }

    int query(int& l, int& r, int L, int R, int p, int& mx){
        if(l <= L && R <= r){
            return lower_bound(tree[p].begin(), tree[p].end(), mx) - tree[p].begin();
        }
        else{
            int M = (L+R)/2;
            if(r <= M)
                return query(l, r, L, M, p*2, mx);
            else if(l > M)
                return query(l, r, M+1, R, p*2+1, mx);
            else
                return query(l, r, L, M, p*2, mx) + query(l, r, M+1, R, p*2+1, mx);
        }
    }

    int query(int l, int r, int mx){
        return query(l, r, 1, n, 1, mx);
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
	vector<pair<int, int>> vect(n+1);
	for(int i=1; i<=n; i++)
		cin >> vect[i].first >> vect[i].second;
	sort(vect.begin()+1, vect.end());
	vector<int> a(n+1);
	for(int i=1; i<=n; i++)
		a[i] = vect[i].second;
	SegmentTree sg(a);
	int ans=0;
	for(int i=1; i<=n; i++){
		ans += sg.query(i, n, vect[i].second);
		//cout << ans << " ";
	}
	return ans;
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
