//11/24/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    cin >> vect[0];int mn=vect[0], mx=vect[0];
    for(int i=1; i<n; i++){
        cin >> vect[i];
        mn = min(mn, vect[i]);
        mx = max(mx, vect[i]);
    }
    vector<int> ans;
    while(mx-mn != 0){
        int mnn = mn/2, mxx = mx/2;
        int add = mn%2==1 && mx%2==0;
        if(mnn%2 == mxx%2 || mnn%2 == 1 && mxx%2 == 0){
            ans.push_back(add);
            mn = (mn+add)/2;
            mx = (mx+add)/2;
        }
        else{
            ans.push_back(add+2);
            mn = (mn+add+2)/2;
            mx = (mx+add+2)/2;
        }
    }
    cout << ans.size() << "\n";
    if(!ans.empty() && ans.size() <= n){
        for(auto& i : ans)
            cout << i << " ";
        cout << "\n";
    }
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}