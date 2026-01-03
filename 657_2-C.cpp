//2023/12/6
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int MX = 0;
    priority_queue<pair<int, int>> B;
    priority_queue<int> A;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        B.push(make_pair(b, a));
        A.push(a);
    }
    B.push(make_pair(0, 0));
    int mx = 0, sum=0, ans = 0;
    while(n && !B.empty()){
        if(!A.empty() && A.top() >= B.top().first){
            sum += A.top();
            A.pop();
            n--;
        }
        else{
            if(A.empty() || B.top().second > A.top())
                mx = max(mx, B.top().first*n+sum);
            else
                mx = max(mx, B.top().second + B.top().first*(n-1)+sum);
            B.pop();
        }
    }
    cout << max(mx, sum) << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}