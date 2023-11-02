//11/2/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define MOD 1000000007
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i];
        st.insert(vect[i]);
    }
    int last = 0;
    for(auto& i : st){
        if(last != i) break;
        last++;
    }
    vect.push_back(last);
    vector<int> ans(n+1);
    for(int i=0; i<=n; i++){
        ans[(i+k)%(n+1)] = vect[i];
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
    return 0;
}
/*
thoughts:
    soo... here i made a classic Anemois mistake...
    I didn't read the question properly and though that this was WAYYY harder than is should
    I though that the starting array wouldn't be 0 <= ai <= n and wrote a bunch of code processing that
    but I prevailed in the end so... :)
process:
    basically this is a loop
    the last number will go to the front
    there will be one number missing from 0~n
    find it and append it
    calculate where the number will end up with ans[(i+k)%(n+1)] = vect[i]
*/