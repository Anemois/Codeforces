//2023/10/30
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

#define int long long

using namespace std;

int solve(){
    int n;
    cin >> n;
    deque<int> vect(n);
    for(int i=0; i<n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end());
    int combo = 0, cnt=0;
    while(!vect.empty()){
        //cout << cnt << " : ";
        //for(auto i : vect)
        //    cout << i << " ";
        //cout << "\n";
        if(vect.size() == 1){
            if(vect[0] == 1) return cnt+1;
            cnt += (max(vect[0] - combo, 0LL)+1)/2 + 1;
            return cnt;
        }
        int x = min(vect.front(), vect.back() - combo);
        combo += x;
        cnt += x;
        vect.front() -= x;
        if(combo >= vect.back()){
            combo = 0;
            cnt++;
            vect.pop_back();
        }
        if(vect.front() == 0){
            vect.pop_front();
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
