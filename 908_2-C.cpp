//11/7/2023
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

bool solve(){
    int n, k;
    cin >> n >> k;
    vector<int> vect(n);
    vector<vector<int>> can(n);
    for(int i=0; i<n; i++){
        cin >> vect[i];
    }
    int ptr = n-1, t;
    while(1){
        if(vect[ptr] == -1 || k == 0)
            return true;
        if(vect[ptr] > n)
            return false;
        t = ptr;
        ptr = (ptr - vect[ptr] + n)%n;
        vect[t] = -1;
        k--;
    }
}

signed main()
{	
	Anemoi
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        if(solve())
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
	return 0;
}
