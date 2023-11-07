//11/7/2023
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

char solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    return str.back();
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << solve() << "\n";
    }
	return 0;
}
