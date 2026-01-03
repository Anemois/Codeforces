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
    vector<int> l(n), r(n);
    for(int i=0; i<n; i++){
        l[i] = vect[i] + (n-i-1);
        r[i] = vect[i] + i;
    }
    for(int i=1; i<n; i++)
        l[i] = max(l[i], l[i-1]);
    for(int i=n-2; i>=0; i--)
        r[i] = max(r[i], r[i+1]);
    if(n==1)
        return vect[0];
    // for(auto& i : l)
    //     cout << i << " ";
    // cout << "\n";
    // for(auto& i : r)
    //     cout << i << " ";
    // cout << "\n";
    int ans = min(max(vect[0], r[1]), max(vect[n-1], l[n-2]));
    for(int i=1; i<n-1; i++)
        ans = min(ans, max({vect[i], l[i-1], r[i+1]}));
    return ans;
}

signed main(){
    Anemoi
    int n = 1;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}