//11/2/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define MOD 1000000007
using namespace std;

int solve(){
    int n, cnt=0;
    cin >> n;
    set<int> st;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        st.insert(x);
        if(st.find(x+1) != st.end())
            cnt++;
    }
    return cnt;
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
    return 0;
}
/*
thoughts:
    this one i didn't do the classic no read question, i accually got to the conclution pretty quick!
process:
    so if there is a number x and the number x+1 has already been seen before
    because every switch won't change the relative order of the number EXCEPT for the one you choose
    so just count the number of x+1 you've seen before x is seen.
*/