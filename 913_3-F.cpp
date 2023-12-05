//2023/12/5
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<int> vect(200010);
int n;

int solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> vect[i];
    }
    int f=-1, s=-1;
    bool first = true, second = true;
    bool use;
    use = false;
    for(int i=0; i<n-1; i++){
        if(vect[i] > vect[i+1]){
            if(!use){
                use = true;
                f = i+1;
            }
            else{
                first = false;
                break;
            }
        }
    }
    use = false;
    for(int i=0; i<n-1; i++){
        if(vect[i] < vect[i+1]){
            if(!use){
                use = true;
                s = i+1;
            }
            else{
                second = false;
                break;
            }
        }
    }
    if(f==-1)
        return 0;
    if(s==-1)
        return 1;
    first = first && vect[n-1] <= vect[0];
    second = second && vect[n-1] >= vect[0];
    if((!first && !second)){
        return -1;
    }
    //cout << (first ? min(n-f, 2+f) : INT_MAX) << " " << (second ? min(n-s+1, s+1) : INT_MAX) << " ";
    return min(first ? min(n-f, 2+f) : INT_MAX, second ? min(n-s+1, s+1) : INT_MAX);
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}