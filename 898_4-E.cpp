//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

vector<int> vect(200010);

int check(int& n, int x){
    int cnt=0;
    for(int i=0; i<n; i++){
        cnt += max(0LL, x - vect[i]);
        if(cnt > 1e15)
            return cnt;
    }
    return cnt;
}

int solve(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> vect[i];
    int l=0, r=1e15;
    while(l < r){
        int m = (l+r+1)/2;
        if(check(n, m) <= x)
            l = m;
        else
            r = m-1;
    }
    return l;
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
