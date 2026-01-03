//11/2/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define MOD 1000000007
using namespace std;

string solve(){
    int n, a, q;
    cin >> n >> a >> q;
    int plusCnt = a, cnt=a;
    string str;
    cin >> str;
    if(a == n) return "YES";
    for(auto& c : str){
        if(c == '+'){
            plusCnt++;
            if(++cnt == n)
                return "YES";
        }
        else{
            cnt--;
        }
    }
    if(plusCnt < n)
        return "NO";
    return "MAYBE";
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
    even though this is easy i still thought for pretty long... looks like its time to sleep
process:
    keep track of two counts 
    plusCnt is on the assumption that every sub that goes offline hast already read the post
    cnt is that every one that goes online might be one that already read the post
    and if cnt is >= n on any time then that means everybody must have read the post
    if plusCNT < n after all then not all people read the post
    otherwise maybe
*/