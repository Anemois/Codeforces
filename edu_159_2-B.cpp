//2023/12/3
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int n, goal, lesn, task, mx_task;

bool check(int& x){
    return (x*lesn) + (min(mx_task, x*2)*task) >= goal;
}

int solve(){
    
    cin >> n >> goal >> lesn >> task;
    int l = 0, r = n;
    mx_task = (n-1)/7+1;
    //cout << mx_task << "\n";
    while(l<r){
        int m = (l+r)/2;
        if(check(m)){
            r = m;
        }
        else{
            l = m+1;
        }
        //cout << n-m << " ";
    }
    return n-l;
}
signed main(){
    Anemoi
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}