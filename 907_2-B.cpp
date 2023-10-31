//2023/10/30
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

vector<int> twos(32);

void init(){
    int two = 1;
    for(int i=0; i<32; i++){
        twos[i] = two;
        two *= 2;
    }
}

int count(int x){
    int cnt = 0;
    while(x%2 == 0){
        cnt++;
        x /= 2;
    }
    return cnt;
}

vector<int> a(100000), b(100000), dp(32);;
void solve(){
    int n, m;
    cin >> n >> m;
    fill(dp.begin(), dp.end(), -1);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<m; i++)
        cin >> b[i];
    for(int i=0; i<n; i++){
        int cnt = count(a[i]);
        if(dp[cnt] != -1){
            a[i] += dp[cnt];
        }
        else{
            dp[cnt] = a[i];
            for(int j=0; j<m; j++){
                if(a[i]%twos[b[j]] == 0){
                    a[i] += twos[b[j]-1];
                }
            }
            dp[cnt] = a[i] - dp[cnt];
        }
        
    }
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

signed main()
{	
	Anemoi
    init();
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve();
    }
	return 0;
}
