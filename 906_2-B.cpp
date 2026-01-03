//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

bool solve(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool can = true;
    for(int i=1; i<m; i++){
        if(t[i] == t[i-1]){
            can = false;
        }
    }
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            if(!can || s[i-1] == t[0] || s[i] == t[m-1])
                return false;
        }
    }
    return true;
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
	return 0;
}
