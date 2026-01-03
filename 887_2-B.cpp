//11/4/2023 diffuculty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool check(int a, int b, int i){
    if(i == 0)
        return true;
    if(a > b)
        return false;
    return check(b-a, a, i-1);
}

int solve(){
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int a = n/2, b = (n+1)/2;
    int x = k-2;
    while(a >= 0 && b <= n){
        if(check(a, b, x))
            cnt++;
        a--;b++;
    }
    return cnt;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}