//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    int x=1;
    bool zero = true;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        if(vect[i] == 0 && zero)
            zero = false;
        else 
            x *= vect[i];
    }
    if(!zero) return x;
    int mx=INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx, x/vect[i] * (vect[i]+1));
    }
    return mx;
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
