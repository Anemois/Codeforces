#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

int solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans1 = 4; 
    for(int i=0; i<n-3; i++){ 
        int diff=(str[i]!='2')+(str[i+1]!='0')+(str[i+2]!='2')+(str[i+3]!='6'); 
        ans1 = min(ans1, diff);
    } 
    //case 2:del 2025
    int ans2 = 0;
    for(int i=0; i<n-3; i++){ 
        if(str[i]=='2'&&str[i+1]=='0'&&str[i+2]=='2'&&str[i+3]=='5')
            ans2++; 
    } 
    return min(ans1, ans2);
}

int main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        cout << solve() << "\n";
}