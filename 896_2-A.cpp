//10/29/2023 difficulty:900
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vect(n+1);
    for(int i=1; i<=n; i++)
        cin >> vect[i];
    vector<pair<int, int>> ans;
    if(n%2 == 0){
        ans.push_back(make_pair(1, n));
        ans.push_back(make_pair(1, n));
    }
    else{
        ans.push_back(make_pair(1, n));
        ans.push_back(make_pair(1, n-1));
        ans.push_back(make_pair(n-1, n));
        ans.push_back(make_pair(n-1, n));
    }
    cout << ans.size() << "\n";
    for(auto& i : ans)
        cout << i.first << " " << i.second << "\n"; 
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
}
/*
process:
so at first i saw XOR and went:ahh... another bitwise...
I started to write the inputs then I saw that there are only at most 8 operations
I then saw that the constraints were lower than 100, which is lower than 2^6
I thought that meant that we had to make operations on each bit and make it zero
so I did a complicated solution...
PART 1 complex:
    I looped through all bits
    got the most left and most even right of each bit's 1
    keep track of l, r
    then started to think how to process if there was a odd number of bits.
    as I though of how i then realized that i could just do it with the whole array at once
    and not first get out even's then do singles
PART 2 EZ:
    so basically you first run l=1, r=n to make the whole array the same
    odd number of bits will become all 1 even numbered will become 0
    and if the array.size()%2 == 0 you can just run l=1, r=n again since even bits will go to 0
    if the array.size()%2 == 0 then you first run l=1, r=n-1 to cancel out all bits except for last row
    then run l=n-1, r=n two times, first time making last 2 all 1 or 0, second time canceling out all
*/