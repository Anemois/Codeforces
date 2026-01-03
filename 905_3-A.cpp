//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;
int main()
{
	Anemoi
	unordered_map<char, int> mp = {{'1', 0},{'2', 1},{'3', 2},{'4', 3},{'5', 4},{'6', 5},{'7', 6},{'8', 7},{'9', 8},{'0', 9}};
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int sum=4;
		sum += abs(mp['1'] - mp[s[0]]) + abs(mp[s[1]] - mp[s[0]])+ abs(mp[s[2]] - mp[s[1]])+ abs(mp[s[3]] - mp[s[2]]);
		cout << sum << "\n";
	}
	return 0;
}
