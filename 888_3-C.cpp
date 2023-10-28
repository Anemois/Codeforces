//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#pragma GCC optimize("O2")
using namespace std;

vector<int> vect(200001);

bool solve(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> vect[i];
    int l = n, r = -1;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(vect[i] == vect[0])
            cnt++;
        if(cnt == k){
            l = i;
            break;
        }
    }
    if(vect[0] == vect[n-1] && l != n) return true;
    cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(vect[i] == vect[n-1]){
            cnt++;
        }
        if(cnt == k){
            r = i;
            break;
        }
    }
    return l < r;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        if(solve())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}