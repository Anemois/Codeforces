//2023/11/14 difficulty:1300
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int to(char& f, char& t){
    return (t-f+26)%26;
}

int go(char& a, char& b, char& c, char& d){
    char mx = max(a, max(b, max(c, d)));
    return to(a, mx) + to(b, mx) + to(c, mx) + to(d, mx);
}

int solve(){
    int n;
    cin >> n;
    vector<string> mat(n);
    for(int i=0; i<n; i++)
        cin >> mat[i];
    
    int sum = 0;
    int N = n/2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum += go(mat[i][j], mat[j][n-i-1], mat[n-i-1][n-j-1], mat[n-j-1][i]);
        }
    }
    return sum;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}