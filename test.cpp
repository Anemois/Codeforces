#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

signed main(){
    
    int n = 2000000;
    vector<int> is_prime(n, true);
    for(int i=2; i<=sqrt(n); i++){
        if(is_prime[i]){
            for(int j=i*i; j<n; j+=i)
                is_prime[j] = false;
        }
    }
    int sum=0;
    for(int i=2; i<n; i++){
        if(is_prime[i])
            sum += i;
    }
    cout << sum;
}