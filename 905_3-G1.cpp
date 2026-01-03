//2023/11/12 difficulty:1400
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#pragma GCC optimize("O2")
using namespace std;

int go(vector<int>& a, vector<int>& b, int i, int j, int& n){
	if(i == n || j == n)
		return n;
	if(a[i] < b[j])
		return go(a, b, i+1, j+1, n);
	return min(i, j);
}

int solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	a[0] = 1;
	for(int i=1; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int k=0;
	for(int i=0; i<n; i++){
		if(a[k] < b[i])
			k++;
	}
	return n-k;
}
 
signed main()
{
	Anemoi
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cout << solve() << "\n";
	return 0;
}
/*
thought:
	I just why am I like this...
	I didn't see that you can reorder the array...
	and over thought the question
	I even came up with a solution that was pretty nice :)
	NOTE TO SELF!!!
	READ THE QUESTION PROPERLY
*/