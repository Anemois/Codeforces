//2023/12/24
#include<bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    int x=2;
    while(1){
        unordered_set<int> st;
        for(auto& i : vect){
            st.insert(i%x);
        }
        if(st.size() == 2)
            return x;
        x = x<<1;
    }
    return -1;
}

signed main(){
    Anemoi
    int t=1;
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}