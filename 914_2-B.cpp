//2023/12/12
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int val, i, ans;
};

void solve(){
    int n;
    cin >> n;
    vector<P> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].val;
        vect[i].i = i;
    }
    sort(vect.begin(), vect.end(), [](const P& a, const P& b){return a.val < b.val;});
    vect.push_back({INT64_MAX, -1, 0});
    int sum=0;
    int last=0;
    for(int i=0; i<=n; i++){
        if(sum < vect[i].val){
            while(last < i)
                vect[last++].ans = i-1;
        }
        sum += vect[i].val;
    }
    vect.pop_back();
    sort(vect.begin(), vect.end(), [](const P& a, const P& b){return a.i < b.i;});
    for(auto& i : vect)
        cout << i.ans << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}