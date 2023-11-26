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
    if(n == 1)
        return vect[0];

    vector<int> ltr(n), rtl(n);
    int x = vect[0];
    for(int i=0; i<n; i++){
        x = max(x, vect[i]);
        rtl[i] = x;
        x++;
    }
    x = vect[n-1];
    for(int i=n-1; i>=0; i--){
        x = max(x, vect[i]);
        ltr[i] = x;
        x++;
    }
    int ans=min(max(vect[0], ltr[1]+1), max(vect[n-1], rtl[n-2]+1));
    for(int i=1; i<n-1; i++){
        ans = min(ans, max(vect[i], rtl[i-1] + ltr[i+1] + 1));
    }
    return ans;
}

signed main(){
    Anemoi
    int n = 1;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}