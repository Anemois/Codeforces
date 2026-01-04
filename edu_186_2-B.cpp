#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long

int fastPow(int x, int y){
    int ans=1;
    int pow=x;
    while(y>0){
        if(y&1)
            ans *= pow;
        pow = pow*pow;
        y /= 2;
    }
    return ans;
}

int calc(int start, int len){
    return start * (fastPow(4, len)-1)/(4-1);
}

int solve(){
    int a, b;
    cin >> a >> b;
    int oa, ea;
    int ob, eb;
    int i=0;
    while(calc(1, i) <= a || calc(1, i) <= b){
        if(calc(1, i) <= a)
            oa = i*2-1;
        if(calc(2, i) <= a)
            ea = i*2;
        if(calc(1, i) <= b)
            ob = i*2-1;
        if(calc(2, i) <= b)
            eb = i*2;
        i++;
    }
    //cout << oa << " " << ea << " " << ob << " " << eb << "\n";
    return max( min(min(oa, eb)+1, max(oa, eb)) ,  min(min(ea, ob)+1, max(ea, ob)) );
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--){
        //cout << "ans : ";
        cout << solve() << "\n";
    }
}