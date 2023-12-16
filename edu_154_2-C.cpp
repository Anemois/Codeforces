//2023/12/16 difficulty:1800
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

#define val first
#define ptr second

bool solve(){
	string str;
	cin >> str;
	int cnt = 0, bot=INT_MAX, top=1;
	for(auto& c : str){
		if(c == '+'){
			top = max(min(top, cnt), 1LL);
			cnt++;
		}
		else if(c == '-'){
			if(cnt == bot){
				bot = INT_MAX;
			}
			cnt--;
		}	
		else if(c == '0'){
			if(cnt <= top)
				return false;
			bot = min(bot, cnt);
		}
		else{
			if(cnt >= bot)
				return false;
			top = max(top, cnt);
		}
	}
	return true;
}

signed main()
{
	Anemoi
	int t;
	cin >> t;
	while(t--)
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	return 0;
}
