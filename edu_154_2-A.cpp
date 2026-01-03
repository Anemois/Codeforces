//11/3/2023 difficulty:800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

string solve(){
    string str;
    cin >> str;
    for(int i=8; i>=0; i--){
        switch(str[i]){
            case '1':
                return "31";
            case '3':
                return "13";
            case '7':
                return "17";
            case '9':
                return "19";
        }
    }
    return "-1";
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
    why did it take me so to think if 31 is prime or not?
process:
    there is only 1 ~ 9 and no repeated numbers
    so that means 1, 3, 7, 9... one must come first
    31, 13, 17, 19 are prime so just see which is last and print it out
    since there will always be an answer
*/