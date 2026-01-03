//10/29/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

string solve(){
    int n;
    cin >> n;
    string str, ans;
    cin >> str;
    int cnt = 0;
    for(int i=0; i<n/2; i++){
        if(str[i] != str[n-i-1])
            cnt++;
    }
    //cout << cnt << " ";
    for(int i=0; i<cnt; i++){
        ans += '0';
    }
    if(n%2 == 0){
        for(int i=cnt; i<=n-cnt; i++)
            ans += '0' + ((i-cnt)%2==0);
    }
    else{
        for(int i=cnt; i<=n-cnt; i++)
            ans += '1';
    }
    for(int i = n-cnt+1; i<=n; i++)
        ans += '0';
    return ans;
    
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}
/*
process:
I just saw the pattern and went for it :)
the pattern:
    first get the count of un-palindrome chars
    the first count chars are 0
    and if n is odd then between two's you can change the bit in the middle
    if its even then you can't
    so that is why in the middle odd is 111111 and even is 101010
*/