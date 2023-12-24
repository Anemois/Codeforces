//2023/12/23 difficulty:1800
#include<bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

struct P{
    int has = 0;
    P* zero=nullptr, *one=nullptr;
};

void solve(){
    //cout << "fine\n";
    int n, k;
    cin >> n >> k;
    int mx = -1, a=-1, b=-1;
    P* root = new P();
    vector<int> vect(n+1);
    for(int t=1; t<=n; t++){
        //cout << "fine\n";
        cin >> vect[t];
        int& x = vect[t];
        //cout << str << "\n";
        int now=0, oth=0;
        P* ptr = root;
        for(int i=k-1; i>=0; i--){
            //cout << i << " ";
            if((x>>i) & 1){
                if(ptr->zero == nullptr)
                    ptr->zero = new P();
                if(ptr->one == nullptr)
                    ptr->one = new P();

                if(ptr->one->has){
                    now += 1LL<<i;
                    ptr=ptr->one;
                }
                else if(ptr->zero->has){
                    ptr=ptr->zero;
                }
                else
                    break;
                oth = ptr->has;
            }
            else{
                if(ptr->zero == nullptr)
                    ptr->zero = new P();
                if(ptr->one == nullptr)
                    ptr->one = new P();

                if(ptr->zero->has){
                    now += (1LL<<i);
                    ptr=ptr->zero;
                }
                else if(ptr->one->has){
                    ptr=ptr->one;
                }
                else
                    break;
                oth = ptr->has;
            }
        }
        ptr = root;
        if(now > mx){
            mx = now;
            a = oth;
            b = t;   
            //cout << a << " " << b << "\n";     
        }
        for(int i=k-1; i>=0; i--){
            if((x>>i) & 1){
                if(ptr->one == nullptr)
                    ptr->one = new P();
                ptr=ptr->one;
                ptr->has = t;
            }
            else{
                if(ptr->zero == nullptr)
                    ptr->zero = new P();
                ptr=ptr->zero;
                ptr->has = t;
            }
        }
    }
    //cout << "hi";
    int c = 0;
    for(int i=k-1; i>=0; i--){
        if(!((vect[b]>>i)&1)){
            c += 1LL<<i;
        }
    }
    if(mx == 0)
        cout << "1 2 0\n";
    else
        cout << a << " " << b << " " << c << "\n";
    //cout << mx << ' ' << ((vect[a]^c)&(vect[b]^c)) << '\n';
}

signed main(){
    Anemoi
    int t;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}