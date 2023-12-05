//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    string str;
    cin >> str;
    int big=0, small=0;
    string ans;
    for(int i=str.length()-1; i>=0; i--){
        if(str[i] == 'B')
            big++;
        else if(str[i] == 'b')
            small++;
        else{
            if(isupper(str[i])){
                if(big > 0)
                    big--;
                else
                    ans += str[i];
            }
            else{
                if(small > 0)
                    small--;
                else
                    ans += str[i];
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}