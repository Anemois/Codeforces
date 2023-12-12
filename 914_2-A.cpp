//2023/12/12
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;
    set<pair<int, int>> st;
    st.insert(make_pair(xk+a, yk+b));
    st.insert(make_pair(xk+a, yk-b));
    st.insert(make_pair(xk-a, yk+b));
    st.insert(make_pair(xk-a, yk-b));

    st.insert(make_pair(xk+b, yk+a));
    st.insert(make_pair(xk+b, yk-a));
    st.insert(make_pair(xk-b, yk+a));
    st.insert(make_pair(xk-b, yk-a));
    int ans=0;
    if(st.count(make_pair(xq+a, yq+b)))
        ans++;
    if(st.count(make_pair(xq+a, yq-b)))
        ans++;
    if(st.count(make_pair(xq-a, yq+b)))
        ans++;
    if(st.count(make_pair(xq-a, yq-b)))
        ans++;

    if(st.count(make_pair(xq+b, yq+a)))
        ans++;
    if(st.count(make_pair(xq+b, yq-a)))
        ans++;
    if(st.count(make_pair(xq-b, yq+a)))
        ans++;
    if(st.count(make_pair(xq-b, yq-a)))
        ans++;
    if(a==b)
        ans/=2;
    cout << ans << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}