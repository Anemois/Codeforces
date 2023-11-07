//11/7/2023
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n), ans(n);
    set<int> seen;
    int first=-1;
    bool can = true;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        if(seen.find(vect[i]) == seen.end()){
            seen.insert(vect[i]);
            ans[i] = 1;
        }
        else{
            if(first == -1 || first == vect[i]){
                first = vect[i];
                ans[i] = 2;
            }
            else{
                can = false;
                ans[i] = 3;
            }
        }
        //cout << ans[i] << " ";
    }
    //cout << "\n";
    if(can)
        cout << "-1";
    else
        for(auto& i : ans)
            cout << i << " ";
    cout << "\n";
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve();
    }
	return 0;
}
