//11/3/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<char> vika = {'v', 'i', 'k', 'a'};

bool solve(){
    int m, n;
    cin >> m >> n;
    vector<string> vect(m);
    for(int i=0; i<m; i++){
        cin >> vect[i];
    }  
    int k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vect[j][i] == vika[k]){
                if(++k == 4)
                    return true;
                break;
            }
        }
    }
    return false;
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
    :)
process:
    do a scan line
*/