//11/3/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int last;
    int x;
    vector<int> ans(1);
    cin >> ans[0];
    last = ans[0];
    for(int i=1; i<n; i++){
        cin >> x;
        if(x >= last)
            ans.push_back(x);
        else{
            ans.push_back(1);
            ans.push_back(x);
        }
        last = x;
    }
    cout << ans.size() << "\n";
    for(auto& i : ans)
        cout << i << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
    return 0;
}
/*
thought:
    :)
process:
    just add 1 when the next one is lower than the last one
*/