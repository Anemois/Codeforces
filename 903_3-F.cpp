//2024/11/29 difficulty:1700
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> marked(k);
    for(auto& i : marked) cin >> i;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<n-1; i++){
        int t, f;
        cin >> t >> f;
        graph[t].push_back(f);
        graph[f].push_back(t);
    }
    int far_mark[2];
    vector<int> cnt1(n+1, -1), cnt2(n+1, -1);

    int dist = 0;
    queue<int> pend;
    pend.push(marked[0]);
    cnt1[marked[0]] = 0;
    while(!pend.empty()){
        int siz = pend.size();
        dist++;
        for(int t=0; t<siz; t++){
            int p = pend.front(); pend.pop();
            for(auto& i : graph[p]){
                if(cnt1[i] == -1){
                    pend.push(i);
                    cnt1[i] = dist;
                }
            }
        }
    }
    int furth = -1;
    for(auto& i : marked){
        if(cnt1[i] > furth){
            furth = cnt1[i];
            far_mark[0] = i;
        }
    }
    fill(cnt1.begin(), cnt1.end(), -1);
    pend.push(far_mark[0]);
    cnt1[far_mark[0]] = 0;
    dist = 0;
    while(!pend.empty()){
        int siz = pend.size();
        dist++;
        for(int t=0; t<siz; t++){
            int p = pend.front(); pend.pop();
            for(auto& i : graph[p]){
                if(cnt1[i] == -1){
                    pend.push(i);
                    cnt1[i] = dist;
                }
            }
        }
    }
    furth = -1;
    for(auto& i : marked){
        if(cnt1[i] > furth){
            furth = cnt1[i];
            far_mark[1] = i;
        }
    }
    dist = 0;
    pend.push(far_mark[1]);
    cnt2[far_mark[1]] = 0;
    while(!pend.empty()){
        int siz = pend.size();
        dist++;
        for(int t=0; t<siz; t++){
            int p = pend.front(); pend.pop();
            for(auto& i : graph[p]){
                if(cnt2[i] == -1){
                    pend.push(i);
                    cnt2[i] = dist;
                }
            }
        }
    }

    int ans=INT_MAX;
    for(int i=1; i<=n; i++){
        ans = min(ans, max(cnt1[i], cnt2[i]));
    }

    return ans;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}