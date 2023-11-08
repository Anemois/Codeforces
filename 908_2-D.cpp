//11/7/2023
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(int i=0; i<n; i++) cin >> v1[i];
    for(int i=0; i<m; i++) cin >> v2[i];

    sort(v2.begin(), v2.end(), greater<int>());
    int j = 0;
    for(int i=0; i<n; i++){
        while(j < m && v2[j] >= v1[i]){
            cout << v2[j] << " ";
            j++;
        }
        cout << v1[i] << " ";
    }
    while(j < m){
        cout << v2[j] << " ";
        j++;
    }
    cout << "\n";
}

signed main()
{	
	Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
	return 0;
}
