//2023/12/15 difficulty:1800
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    int n;
    cin >> n;
    int x, sum=0;
    unordered_set<int> tbag;
    tbag.insert(0);
    vector<int> pend;
    for(int i=0; i<n; i++){
        cin >> x;
        sum += x;
        pend.clear();
        for(auto& j : tbag){
            pend.push_back(j+x);
        }
        //cout << "\n";
        for(auto& j : pend)
            tbag.insert(j);
    }
    vector<int> bag;
    for(auto& i : tbag)
        bag.push_back(i);
    sort(bag.begin(), bag.end());
    int t = (sum+a+b-1)/(a+b);
    auto p = lower_bound(bag.begin(), bag.end(), a*t);
    p--;
    int idk = *p;
    p++;
    //cout << sum << " " << t << " " << (*p) << " ";
    return t+max(0LL,b*t >= sum-idk ? 0 : min(((p == bag.end() ? 0 : (*p))-t*a+a-1)/a, (sum-idk+b-1)/(b) - t));
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}