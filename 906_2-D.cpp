//2023/10/28
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

vector<int> vect(200002);

bool solve(){
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    cin >> vect[1];
    for(int i=2; i<=n; i++){
        cin >> vect[i];
        pq.push(make_pair(-(i*k-vect[i]), i));
    }
    int last = pq.size(), sum = vect[1];
    do{
        last = pq.size();
        if(sum >= -pq.top().first){
            sum += vect[pq.top().second];
            pq.pop();
        }
    }   while(!pq.empty() && last != pq.size());
    return pq.empty();
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
