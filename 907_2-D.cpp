//2023/10/31
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long
#define MOD 1000000007
using namespace std;

int go(int l, int r, int x){
    int sum = 0, e = 0, now = 1;
    while(now <= l/x){
        now *= x;
        e++;
    }
    while(true){
        int next = now <= r/x ? now * x : r;
        sum += ((next - max(l, now)) * e)%MOD; 

        if(next == r)
            break;

        now *= x;
        e++;
    }
    return sum%MOD;
}

int solve(){
    int l, r, ans = 0;
    cin >> l >> r;
    r++;
    for(int i=2; 1LL << i < r; i++){
        if(1LL << i > r || 2LL << (i) < l) continue;
        //cout << max(l, 1LL << i) << " " << min(r, 2LL << (i)) << " " << i << "\n";
        ans = (ans + go(max(l, 1LL << i), min(r, 2LL << (i)), i))%MOD;
    }
    return ans;
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
/*
process:
    I gave up...
*/