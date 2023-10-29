//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

bool solve(){
    int n;
    cin >> n;
    map<int, int> mp;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        mp[x]++;
    }
    if(mp.size() == 1)
        return true;
    if(mp.size() > 2)
        return false;
    int a=0, b=0;
    for(auto i : mp){
        if(a == 0)
            a = i.second;
        else
            b = i.second;
    }
    return abs(a - b) <= 1;
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
	return 0;
}
