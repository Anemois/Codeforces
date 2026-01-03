//2023/12/24
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end());
    if(k == vect[0] && k == vect[n-1])
        return 0;
    if(k >= vect[0] && k <= vect[n-1])
      return -1;
    int x = abs(vect[0] - k);
    for(int i=1; i<n; i++){
        x = __gcd(x, abs(vect[i] - k));
    }
    int ans=0;
    for(int i=0; i<n; i++){
          ans += abs(vect[i]-k)/x-1;
    }
    return ans;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}