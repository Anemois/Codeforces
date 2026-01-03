//11/3/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int Over(int targ, int val, int cnt_a, int cnt_b){
    targ -= cnt_a; if(targ <= 0) return 0;
    int n = targ/val + 1;
    int over = n*val;
    if(over - targ > cnt_a) return INT_MAX;
    return max(0LL, n-cnt_b);
}

int Before(int targ, int val, int cnt_a, int cnt_b){
    targ -= cnt_a; if(targ <= 0) return 0;
    int n = targ/val;
    int before = n*val;
    return max(0LL, n-cnt_b) + targ - before;
}

int solve(){
    int targ, val, cnt_a, cnt_b;
    cin >> targ >> val >> cnt_a >> cnt_b;
    return min(Over(targ, val, cnt_a, cnt_b), Before(targ, val, cnt_a, cnt_b));
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}
/*
thought:
    why do i feel like im getting worse and worse at coding...
    i went on the complete wrong direction at first
*/