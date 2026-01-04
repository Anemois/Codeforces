#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long

int solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
    for(int i=0; i<n; i++)
        cin >> c[i];
    int ab=0, bc=0;
    for(int i=0; i<n; i++){
        bool hasab = true;
        bool hasbc = true;
        for(int j=0; j<n; j++){
            if(a[0+j] >= b[(i+j)%n])
                hasab = false;
            if(b[(i+j)%n] >= c[0+j])
                hasbc = false;
        }
        if(hasab)
            ab++;
        if(hasbc)
            bc++;
    }
    return ab*bc*n;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--){
        // cout << "ans : ";
        cout << solve() << "\n";
    }
}