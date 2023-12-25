//2023/12/24
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans=0;
    vector<bool> seen(26, false);
    for(int i=0; i<n; i++){
        if(seen[str[i]-'a'] == false){
            ans += n-i;
            seen[str[i]-'a'] = true;
        }
    }
    return ans;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}