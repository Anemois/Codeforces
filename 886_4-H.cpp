//2023/12/23 difficulty:1700
#include<bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int p, dist;
};

bool go(vector<vector<P>>& graph, vector<int>& cords, int p){
    if(cords[p] == INT_MIN){
        cords[p] = 0;
    }
    for(auto& i : graph[p]){
        if(cords[i.p] == INT_MIN){
            cords[i.p] = cords[p]+i.dist;
            if(!go(graph, cords, i.p))
                return false;
        }
        else{
            if(cords[i.p] != cords[p]+i.dist)
                return false;
        }
    }
    return true;
}

bool solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<P>> graph(n+1);
    for(int i=0; i<k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, -c});
    }
    vector<int> cords(n+1, INT_MIN);
    for(int i=1; i<=n; i++){
        if(cords[i] == INT_MIN)
            if(!go(graph, cords, i))
                return false;
    }
    return true;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        if(solve())
            cout << "YES\n";
        else    
            cout << "NO\n";
    
    return 0;
}