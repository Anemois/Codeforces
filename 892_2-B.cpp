//2023/10/28
#include <bits/stdc++.h>

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long

using namespace std;

int solve(){
    int n;
    cin >> n;
    int sum=0;
    int real_mn = INT_MAX, mn_two=INT_MAX;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        int mn1=INT_MAX, mn2=INT_MAX;
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            if(x < mn1){
                mn2 = mn1;
                mn1 = x;
            }
            else if(x < mn2){
                mn2 = x;
            }
        }
        sum += mn2;
        if(mn2 < mn_two){
            mn_two = mn2;
        }
        real_mn = min(real_mn, mn1);
    }
    return sum - mn_two + real_mn;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cout << solve() << "\n";
    }
}