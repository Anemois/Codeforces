//2023/11/26
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct Node{
    int l, r;
    char op;
};

vector<Node> tree;

int go(int p){
    if(p == 0)
        return INT_MAX;
    if(tree[p].l == 0 && tree[p].r == 0)
        return 0;
    if(tree[p].op == 'U')
        return min(go(tree[p].l), go(tree[p].r))+1;
    if(tree[p].op == 'L')
        return min(go(tree[p].l), go(tree[p].r)+1);
    
    return min(go(tree[p].l)+1, go(tree[p].r));
}

int solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    tree.resize(n+1);
    for(int i=1; i<=n; i++){
        int l, r;
        cin >> l >> r;
        tree[i].l = l;
        tree[i].r = r;
        tree[i].op = str[i-1];
    }
    return go(1);
}

signed main(){
    Anemoi
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
        cout << solve() << "\n";
}