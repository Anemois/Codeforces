//11/4/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int last_zero;

string Round(string str, int i){
    int j;
    for(j = i-1; j>=0; j--){
        if(str[j] != '9'){
            break;
        }
    }
    for(int k=last_zero; k>j; k--)
        str[k] = '0';
    last_zero = j;
    if(j == -1){
        str = "1" + str;
    }
    else{
        str[j] = str[j]+1;
    }
    return str;
}

string solve(){
    string str;
    cin >> str;
    last_zero = str.length()-1;
    for(int i=str.length()-1; i>=0; i--){
        if(str[i] >= '5'){
            str = Round(str, i);
        }
    }
    return str;
}

signed main(){  
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}