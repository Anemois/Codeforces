//2023/12/14 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MOD = 998244353;

int solve(){
	int n;
	cin >> n;
	vector<int> ooe(5, 0), oeo(5, 0), eoo(5, 0), eee(5, 0);
	int temp;
	for(int i=0; i<n; i++){
		cin >> temp;
		if(temp%2==1){
			oeo[0] = (oeo[0] + oeo[2] + 1)%MOD;
			oeo[2] = (oeo[2] + oeo[1])%MOD;

			oeo[3] = (oeo[3] + 1)%MOD;
			//--------------------------------
			ooe[1] = (ooe[1] + ooe[0])%MOD;
			ooe[0] = (ooe[0] + ooe[2] + 1)%MOD;

			ooe[4] = (ooe[4] + ooe[3])%MOD;
			ooe[3] = (ooe[3] + 1)%MOD;
			//--------------------------------
			eoo[2] = (eoo[2] + eoo[1])%MOD;
			eoo[1] = (eoo[1] + eoo[0])%MOD;

			eoo[4] = (eoo[4] + eoo[3])%MOD;
		}
		else{
			oeo[1] = (oeo[1] + oeo[0])%MOD;

			oeo[4] = (oeo[4] + oeo[3])%MOD;
			//--------------------------------
			ooe[2] = (ooe[2] + ooe[1])%MOD;
			//--------------------------------
			eoo[0] = (eoo[0]+eoo[2]+1)%MOD;

			eoo[3] = (eoo[3] + 1)%MOD;
			//--------------------------------
			int t = eee[2];
			eee[2] = (eee[2] + eee[1])%MOD;
			eee[1] = (eee[1] + eee[0])%MOD;
			eee[0] = (eee[0] + t + 1)%MOD;
			eee[4] = (eee[4] + eee[3])%MOD;
			eee[3] = (eee[3] + 1)%MOD;
		}
	}
	//cerr << oeo[0] << " " << oeo[1] << " " << oeo[2] << " " << oeo[3] << " " << oeo[4] << "\n";
	//cerr << ooe[0] << " " << ooe[1] << " " << ooe[2] << " " << ooe[3] << " " << ooe[4] << "\n";
	//cerr << eoo[0] << " " << eoo[1] << " " << eoo[2] << " " << eoo[3] << " " << eoo[4] << "\n";
	//cerr << eee[0] << " " << eee[1] << " " << eee[2] << " " << eee[3] << " " << eee[4] << "\n";
	return ((oeo[0]+oeo[1]+oeo[2]-oeo[3]-oeo[4]) + (ooe[0]+ooe[1]+ooe[2]-ooe[3]-ooe[4]) +
		(eoo[0]+eoo[1]+eoo[2]-eoo[3]-eoo[4]) + (eee[0]+eee[1]+eee[2]-eee[3]-eee[4]))%MOD;
}

signed main(){
	Anemoi
	int t=1;
	while(t--)
		cout << solve();
	return 0;
}

