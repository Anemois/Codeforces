//2023/12/24
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    
    for(int i=0; i<n; i++)
        cin >> l[i];
    for(int i=0; i<n; i++)
        cin >> r[i];
    for(int i=0; i<n; i++)
        cin >> c[i];

    sort(l.begin(), l.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    
    int j=0;
    priority_queue<int, vector<int>, greater<int>> pq, best;
    int ans=0;
    for(int i=0; i<n; i++){
        while(j<n && r[j] > l[i])
            pq.push(r[j++]);
        best.push(pq.top()-l[i]);
        pq.pop();
        
    }
    for(int i=0; i<n; i++){
        ans += c[i]*(best.top());
        best.pop();
    }
    return ans;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}