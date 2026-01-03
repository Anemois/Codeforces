//2023/12/19 difficulty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;   
    vector<pair<int, int>> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i].first;
        vect[i].second = i;
    }
    sort(vect.begin(), vect.end(), greater<pair<int, int>>());
    if(vect[0].first == 0){
        cout << "YES\n";
        for(int i=0; i<n; i++)
            cout << -1 << " ";
        cout << "\n";
        return;
    }
    vector<pair<int, pair<int, int>>> vect2;
    vector<int> ans(n);
    int x = 3*n, last=0;
    for(int i=0; i<n; i++){
        if(vect[i].first >= vect2.size()+1LL){
            vect2.push_back(make_pair(x, vect[i]));
            x -= 2;
            last = i+1;
        }
        else{
            if(vect[i].first == last){
                vect2.push_back(make_pair(-(x+1), vect[i]));
            }
            else{
                vect2.push_back(make_pair(-(vect2[vect[i].first].first+1), vect[i]));
            }
        }
    }
    sort(vect2.begin(), vect2.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
        return abs(a.first) > abs(b.first);
    });
    // for(auto& i : vect2)
        // cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    bool can = true;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(vect2[i].first > 0){
            if(vect2[i].second.first != n-i+cnt){
                can = false;
                break;
            }
            cnt++;
        }
        else{
            if(vect2[i].second.first != cnt){
                can = false;
                break;
            }
        }
    }
    if(!can){
        cout << "NO\n";
        return;
    }

    int now=n;
    ans[vect2[0].second.second] = now * (vect2[0].first>= 0 ? 1 : -1);
    for(int i=1; i<n; i++){
        if(vect2[i].first != vect2[i-1].first)
            now--;
        ans[vect2[i].second.second] = now * (vect2[i].first>= 0 ? 1 : -1);
    }
    cout << "YES\n";
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        solve();
}