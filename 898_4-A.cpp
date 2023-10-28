//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

bool solve(){
    string s;
    cin >> s;
    int cnt = (s[0] == 'a') + (s[1] == 'b') + (s[2] == 'c');
    return cnt >= 1;
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
