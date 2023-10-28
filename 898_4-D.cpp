//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(str[i] == 'B'){
            cnt++;
            i += k-1;
        }
    }
    return cnt;
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
