//2023/12/21
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int a, b;
};

int solve(){
    int n;
    cin >> n;
    vector<P> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i].a;
    for(int i=0; i<n; i++)
        cin >> vect[i].b;
    
    sort(vect.begin(), vect.end(), [](const P& a, const P& b){
        return (a.a-1) + a.b > (b.a-1) + b.b;
    });

    int x = 0;
    for(int i=0; i<n; i++){
        if(i%2==0)
            x += vect[i].a-1;
        else
            x -= vect[i].b-1;
    }
    return x;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}