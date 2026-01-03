//2023/12/9 difficulty:1700
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> vect(n+1);
    for(int i=0; i<n; i++){
        int u, v;
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }
    int PTR = -1;
    int dist1 = -1;
    vector<int> seen(n+1, -1);
    int mn = INT_MAX;
    auto dfs = [&](auto&& dfs, int last, int p, int dist) -> void{
        if(p == PTR)
            mn = min(mn, dist);
        if(seen[p] != -1){
            if(PTR == -1)
                PTR = p;
            return;
        }
        seen[p] = dist;
        for(auto& i : vect[p])
            if(i != last)
                dfs(dfs, p, i, dist+1);
        seen[p] = -1;
    };
    dfs(dfs, -1, b, 0);
    dfs(dfs, -1, b, 0);
    dist1 = mn;
    mn = INT_MAX;
    dfs(dfs, -1, a, 0);
    return dist1 < mn;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
}