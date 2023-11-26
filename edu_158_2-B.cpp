//11/24/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    for(int i=n-1; i>=1; i--){
        vect[i] -= vect[i-1];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += max(0LL, vect[i]);
        //cout << vect[i] << " ";
    }
        
    return ans-1;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}