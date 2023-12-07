//2023/12/7 difficulty:2200
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> str(n);
    vector<int> deg(n, 0), to(n);
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        str[i] = c == '1';
    }
    for(int i=0; i<n; i++){
        cin >> to[i];
        to[i]--;
        deg[to[i]]++;
    }
    vector<int> pend;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(deg[i] == 0)
            pend.push_back(i);
    }
    while(!pend.empty()){
        int p = pend.back();
        pend.pop_back();
        if(str[p]){
            ans.push_back(p);
            str[p] = !str[p];
            str[to[p]] = !str[to[p]];
        }
        if(--deg[to[p]] == 0)
            pend.push_back(to[p]);
    }
    vector<bool> seen(n, false);
    for(int i=0; i<n; i++){
        if(deg[i] == 0 || seen[i]) continue;
        pend.clear();
        vector<bool> pstr;
        int p = i, cnt=0;
        while(!seen[p]){
            cnt += str[p];
            pend.push_back(p);
            pstr.push_back(str[p]);
            seen[p] = true;
            p = to[p];
            //cerr << cnt << " ";
        }
        //cerr << "\n";
        pend.push_back(p);
        pstr.push_back(str[p]);
        if(cnt%2 == 1){
            //for(auto j : str)
                //cerr << j << " ";
            //cerr << "\n";
            //for(auto& j : pend)
                //cerr << j << " ";
            //cerr << cnt << " ";
            cout << "-1\n";
            return;
        }
        int t = pend.size()-1;
        vector<int> ans1;
        vector<bool> pstr1 = pstr;
        for(int j=0; j<t; j++){
            if(j==0 || pstr1[j]){
                ans1.push_back(pend[j]);
                pstr1[j] = !pstr1[j];
                pstr1[j+1] = !pstr1[j+1];
            }
        }
        vector<int> ans2;
        vector<bool> pstr2 = pstr;
        for(int j=0; j<t; j++){
            if(j!=0 && pstr2[j]){
                ans2.push_back(pend[j]);
                pstr2[j] = !pstr2[j];
                pstr2[j+1] = !pstr2[j+1];
            }
        }
        if(ans1.size() < ans2.size()){
            for(auto& j : ans1)
                ans.push_back(j);
        }
        else{
            for(auto& j : ans2)
                ans.push_back(j);
        }
        //cerr << "\nye\n";
    }

    cout << ans.size() << "\n";
    for(auto& i : ans)
        cout << i+1 << " ";

    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}