#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

vector<int> yes = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

int go(int& i, int& j){
    return min(yes[i], yes[j]);
}

int solve(){
    vector<string> mat(10);
    for(int i=0; i<10; i++)
        cin >> mat[i];
    int cnt=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mat[i][j] == 'X')
                cnt += go(i, j);
        }
    }
    return cnt;
}

signed main()
{	
	Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << solve() << "\n";
    }
	return 0;
}
