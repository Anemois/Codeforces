//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

vector<int> a(1005), b(1005);

long long solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int s=0, l=0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    for(int i=0; i<n; i++) if(a[i] < a[s]) s = i;
    for(int i=0; i<m; i++) if(b[i] > b[l]) l = i;
    if(a[s] < b[l]) swap(a[s], b[l]);
    if(k%2==0){
        s = 0, l = 0;
        for(int i=0; i<n; i++) if(a[i] > a[l]) l = i;
        for(int i=0; i<m; i++) if(b[i] < b[s]) s = i;
        swap(a[l], b[s]);
    }
    long long ans=0;
    for(int i=0; i<n; i++)
        ans += (long long)a[i];
    return ans;
}
 
int main(){
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cout << solve() << "\n";
	return 0;
}