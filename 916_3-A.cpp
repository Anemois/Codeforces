//2023/12/21
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
    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[str[i]-'A'+1]++;
    }
    int cnt=0;
    for(auto& i : mp){
        if(i.second >= i.first)
            cnt++;
    }
    return cnt;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}