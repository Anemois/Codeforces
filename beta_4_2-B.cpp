//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

signed main(){
    Anemoi
    int n, total;
    cin >> n >> total;
    struct P{
        int s, e;
    };
    vector<P> vect(n);
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].s >> vect[i].e;
        ans[i] = vect[i].s;
        total -= vect[i].s;
    }
    if(total < 0){
        cout << "NO";
        return 0;
    }
    for(int i=0; i<n; i++){
        int x = min(total, vect[i].e - vect[i].s);
        total -= x;
        ans[i] += x;
        if(total == 0) break;
    }
    if(total > 0){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(auto& i : ans)
        cout << i << " ";
}