//2023/12/10 difficulty:1700
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;


const int MX = 34;

unordered_map<int, int> twos;

void init(){
    int t = 1, cnt=0;
    while(cnt<MX){
        twos[t] = cnt++;
        t*=2;
    }
}

bool solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    int s=0;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        s+=vect[i];
    }
        
    if(s%n != 0) return false;
    
    s/=n;

    vector<int> cnt(MX, 0);
    
    for(auto& x : vect){
        bool can = false;
        for(int i=0; i<MX; i++){
            int minus = x + (1LL<<i) - s;
            if(twos.find(minus) != twos.end()){
                cnt[twos[minus]]++;
                cnt[i]--;
                can = true;
                break;
            }
        }
        if(!can) return false;
    }

    for(int i=0; i<MX; i++)
        if(cnt[i] != 0) return false;
    return true;
}

signed main(){
    Anemoi
    init();
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
}