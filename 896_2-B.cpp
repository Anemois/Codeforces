//10/29/2023 difficulty:1100
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    struct P{
        int x, y;
    };
    vector<P> vect(n+1);
    int dist1=10000000000, dist2 = 10000000000;
    for(int i=1; i<=n; i++){
        cin >> vect[i].x >> vect[i].y;
    }
    for(int i=1; i<=k; i++){
        dist1 = min(dist1, abs(vect[i].x - vect[a].x) + abs(vect[i].y - vect[a].y));
        dist2 = min(dist2, abs(vect[i].x - vect[b].x) + abs(vect[i].y - vect[b].y));
    }
    //cout << dist1 << " " << dist2 << "//";
    return min(abs(vect[a].x - vect[b].x) + abs(vect[a].y - vect[b].y), dist1 + dist2);
}

signed main(){
    Anemoi
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}
/*
process:
I saw and had a thought that this was a greedy solution
i started to think how would a plane go the lowest money
there were 4 cases a_big b_big, a_small b_big, a_big b_small, a_small b_small
the both big is just 0
the one small one big is the closest big city to small city
the two small could either be small -> big -> big -> small or small -> small and get the min
then as i wrote the code I found out that i could just check the distance of the towns to all the big citys
and since if the start/end city is in big itself then it would be 0
but i got wrong once bc I didn't think that the ans would be bigger than INT_MAX
changed that bigget and AC
*/