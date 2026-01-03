//2023/12/16
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
    vector<char> c = {str[n-1]};
    vector<int> ptr = {n-1};
    int cnt=0;
    for(int i=n-2; i>=0; i--){
        if(str[i] > c.back()){
            cnt = c.size();
            c.push_back(str[i]);
            ptr.push_back(i);
        }
        else if(str[i] == c.back()){
            c.push_back(str[i]);
            ptr.push_back(i);
        }
    }
    reverse(ptr.begin(), ptr.end());
    int j=0, N = ptr.size();
    string ans;
    for(int i=0; i<n; i++){
        if(j < N && ptr[j] == i){
            ans += c[j];
            j++;
        }
        else{
            ans += str[i];
        }
    }
    bool is = true;
    for(int i=0; i<n-1; i++){
        if(ans[i] > ans[i+1]){
            is = false;
            break;
        }
    }
    //cout << ans << "\n";
    if(is)
        return cnt;
    else
        return -1;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}