//2023/12/23 difficulty:1700
#include<bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    bool two = false, one = false;
    vector<int> vect(n);
    vector<int> best;
    for(int i=0; i<n; i++){
        cin >> vect[i];
        if(vect[i] == 0){
            if(two)
                best.push_back(2);
            else if(one)
                best.push_back(1);
            best.push_back(0);
            two = false;
            one = false;
        }
        else if(vect[i] == 1)
            one = true;
        else if(vect[i] == 2)
            two = true;
    }
    if(two)
        best.push_back(2);
    else if(one)
        best.push_back(1);
    n = best.size();
    vector<bool> ans(n, false);
    for(int i=0; i<n; i++){
        if(best[i] == 2){
            if(i-1>=0)
                ans[i-1] = true;
            if(i+1<n)
                ans[i+1] = true;
        }
        if(best[i] == 1){
            if(i-1>=0 && ans[i-1] == false)
                ans[i-1] = true;
            else if(i+1<n)
                ans[i+1] = true;
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++)
        if(!ans[i])
            cnt++;
    return cnt;
}

signed main(){
    Anemoi
    int t=1;
    while(t--)
        cout << solve() << "\n";
    return 0;
}