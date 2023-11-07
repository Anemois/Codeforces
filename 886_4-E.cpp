//11/4/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int go(const vector<int>& vect, int x){
    int ret=0;
    for(auto& i : vect)
        ret += (i+x)*(i+x);
    return ret;
}

int solve(){
    int n, targ;
    cin >> n >> targ;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    int l = 0, r = sqrt(1000000000000000000/n)+1;
    while(l < r){
        int m = (l+r)/2;
        if(go(vect, m) < targ)
            l = m+1;
        else
            r = m;
    }
    return l/2;
}

signed main(){
    Anemoi
    int n = 1;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}
/*
thought:
    nice question :)
    so I smelled that this was a binary search when i saw the question
    I spent most of my time thinking how to prevent overflow
    I came to the conclusion that r = sqrt(1000000000000000000/n)+1
    and it worked! so yay
process:
    get all the numbers
    do a binary search of the answer
    watch out for overflow tho
    also remember to /2 at the end when return because the cardboard goes on left and right
    making the answer /2
*/