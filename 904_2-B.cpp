//11/11/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0;
    for(auto& c : str)
        if(c == '1')
            cnt++;
    //cerr << cnt << "\n";
    int to = n-1, ans=0;
    for(int i=n-1; i>=cnt; i--){
        if(str[i] == '1'){
            to = min(to, i);
            while(str[--to] == '1')
                ;
            str[to] = '1';
            ans += i-to;
        }
        cout << ans << " ";
    }
    for(int i = 0; i<cnt; i++)
        cout << "-1 ";
    cout << "\n";
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}
/*
thought:
    man... I was stuck on that min for so long...
    why did i think that it was max
*/