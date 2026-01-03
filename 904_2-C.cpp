//2023/11/19 difficulty:1700
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;

int solve(){
    int q, n;
    cin >> q >> n;
    vector<pii> vect(q);
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        vect[i] = make_pair(l, r);
    }
    sort(vect.begin(), vect.end());
    int mx=0, cnt=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<q; i++){
        if(vect[i].F == 1) continue;
        while(!pq.empty() && pq.top() < vect[i].F){
            //cout << pq.top() << " ";
            mx = max(mx, cnt);
            cnt--;
            pq.pop();
        }
        cnt++;
        pq.push(vect[i].S);
    }
    mx = max(mx, cnt);
    while(!pq.empty())
        pq.pop();
    cnt=0;
    for(int i=0; i<q; i++){
        if(vect[i].S == n) continue;
        while(!pq.empty() && pq.top() < vect[i].F){
            //cout << pq.top() << " ";
            mx = max(mx, cnt);
            cnt--;
            pq.pop();
        }
        cnt++;
        pq.push(vect[i].S);
    }
    mx = max(mx, cnt);
    return mx;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}