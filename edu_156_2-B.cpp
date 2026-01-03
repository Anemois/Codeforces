// 11/10/2023 difficulty:1200
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

typedef long double ld;

struct P{
    ld x, y;
};

ld dist(P& a, P& b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

ld solve(){
    P p, a, b, zero = {0, 0};
    cin >> p.x >> p.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    ld za = dist(zero, a), zb = dist(zero, b);
    ld pa = dist(p, a), pb = dist(p, b);
    ld two = dist(a, b)/4;
    //cout << za << " " << zb << " " << pa << " " << pb << " " << two << "\n";
    if(pa <= pb){
        if(pa >= za){
            // cout << 1 << " ";
            return pa;
        }
        if(za <= zb){
            // cout << 2 << " ";
            return za;
        }
        // cout << 3 << " ";
        return max(max(zb, two), pa);
    }
    else{
        if(pb >= zb){
            // cout << 4 << " ";
            return pb;
        }
        if(zb <= za){
            // cout << 5 << " ";
            return zb;
        }
        // cout << 6 << " ";
        return max(max(za, two), pb);
    }
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cout << fixed << setprecision(10) << sqrt(solve()) << "\n";
    }
    return 0;
}