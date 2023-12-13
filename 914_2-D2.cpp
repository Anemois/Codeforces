//2023/12/13
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    deque<int> dq;
    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.back() <= a[i]) dq.pop_back();
        while(!dq.empty() && dq.front() > b[i]) dq.pop_front();
        dq.push_back(a[i]);
        if(dq.front() == b[i]) a[i] = b[i];
    }
    dq.clear();
    for(int i=n-1; i>=0; i--){
        while(!dq.empty() && dq.back() <= a[i]) dq.pop_back();
        while(!dq.empty() && dq.front() > b[i]) dq.pop_front();
        dq.push_back(a[i]);
        if(dq.front() == b[i]) a[i] = b[i];
    }
    for(int i=0; i<n; i++)
        if(a[i] != b[i])
            return false;
    return true;
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