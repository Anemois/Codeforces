//11/8/2023 difficulty:1300
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
    int resp;
    if(vect[0] != 0){
        cout << 0 << "\n";
        cout.flush();
        cin >> resp;
        return false;
    }
    int mn = 0;
    for(int i=0; i<n; i++){
        if(vect[i] != mn)
            break;
        mn++;
    }
    do{
        cout << mn << "\n";
        cout.flush();
        cin >> resp;
        if(resp == -1)
            return false;
        if(resp == -2)
            return true;
        else
            mn = resp;
    }while(1);
    

}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        if(solve())
            break;
}