//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> place;
    for(int i=0; i<str.length()/2+1; i++){
        if(str[i] == str[str.length()-i-1]){
            if(str[i] == '0'){
                place.push_back(str.length()-i);
                str.insert(str.length()-i, "01");
            }
            else{
                place.push_back(i);
                str.insert(i, "01");
            }
        }
        if(place.size() > 300) break;
    }
    if(place.size() > 300){
        cout << "-1\n";
    }
    else{
        cout << place.size() << "\n";
        for(auto& i : place)
            cout << i << " ";
        cout << "\n";
    }

}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve();
    }
	return 0;
}
