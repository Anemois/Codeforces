//2023/11/13 difficulty:1300
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    set<int> all;
    vector<vector<int>> vect(n);
    vector<vector<bool>> nums(51, vector<bool>(n, true));
    for(int i=0; i<n; i++){
        int k, x;
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> x;
            all.insert(x);
            vect[i].push_back(x);
            nums[x][i] = false;
        }
    }
    int ans = 0;
    for(auto& i : all){
        set<int> st;
        for(int j=0; j<n; j++){
            if(nums[i][j]){
                for(auto& k : vect[j])
                    st.insert(k);
            }
        }
        ans = max(ans, (int)st.size());
    }
    return ans;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}