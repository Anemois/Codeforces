//2023/12/21
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> vect(3, vector<pair<int, int>>(n));
    for(int i=0; i<n; i++){cin >> vect[0][i].first;vect[0][i].second=i;};
    for(int i=0; i<n; i++){cin >> vect[1][i].first;vect[1][i].second=i;};
    for(int i=0; i<n; i++){cin >> vect[2][i].first;vect[2][i].second=i;};
    int arr[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {2, 0, 1}, {2, 1, 0}, {1, 2, 0}};
    sort(vect[0].begin(), vect[0].end(), greater<pair<int, int>>());
    sort(vect[1].begin(), vect[1].end(), greater<pair<int, int>>());
    sort(vect[2].begin(), vect[2].end(), greater<pair<int, int>>());
    int mx=0;
    for(int i=0; i<6; i++){
        set<int> used;
        int sum=0;
        for(int j=0; j<3; j++){
            //cout << arr[i][j] << " ";
            int k=0;
            while(used.find(vect[arr[i][j]][k].second) != used.end())
                k++;
            used.insert(vect[arr[i][j]][k].second);
            sum += vect[arr[i][j]][k].first;
        }
        //cout << "\n";
        mx = max(mx, sum);
    }
    return mx;
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}