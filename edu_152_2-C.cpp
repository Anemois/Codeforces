//2023/12/22 difficulty:1600
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> l(n+1, 0), r(n+1, 0);
    int last = 0;
    for(int i=1; i<=n; i++){
        l[i] = l[i-1] + (str[i-1]=='1');
        //cout << l[i] << " ";
        if(str[i-1] == '0')
            last = i;
        r[i] = last;
    }
    vector<unordered_set<int>> ans(n+1); 
    
    while(q--){
        int a, b;
        cin >> a >> b;
        b = r[b];
        if(b <= a || l[b] - l[a-1] == 0){
            ans[0].insert(0);
        }
        else{
            ans[b].insert(l[b] - l[a-1]);
        }
    }
    // for(auto& i : r)
    //     cout << i << " ";
    // cout << "\n";
    int cnt=0;
    for(int i=0; i<=n; i++){
        //cout << i << " : ";
        // for(auto j : ans[i])
        //     cout << j << " ";
        //cout << "\n";
        cnt += ans[i].size();
    }
    return cnt;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        cout << solve() << "\n";
}