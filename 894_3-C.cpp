//11/3/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    
    int j = n-1;
    for(int i=0; i<n; i++){
        while(vect[j] <= i){
            if(--j == -1)
                return false;
        }
        if(vect[i] != j+1)
            return false;
    }
    return true;
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}
/*
thought:
    easy refresher of the day!
process:
    check if there are vect[i] of numbers that are >= i
*/