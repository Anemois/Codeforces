//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<int> vect = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};

void solve(){
    string str;
    cin >> str;
    
    int sum=1;
    for(auto& c : str){
        sum *= vect[c-'0'];
    }
    cout << sum << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}