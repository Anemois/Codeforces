//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> cnt(26, 0);
    for(auto& c : str){
        cnt[c-'a']++;
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    int sum=0;
    for(int i=1; i<26; i++)
        sum += cnt[i];
    cout << max(n%2, cnt[0]-sum) << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}