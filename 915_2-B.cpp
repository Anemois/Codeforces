//2023/12/16
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> graph(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u]++;
        graph[v]++;
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(graph[i] == 1)
            cnt++;
    }
    return (cnt+1)/2;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}