//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

map<string, int> mp;

string solve(){
    string str;
    cin >> str;
    if(mp.find(str) == mp.end()){
        mp[str] = 0;
        return "OK";
    }
    mp[str]++;
    return str + to_string(mp[str]);
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}