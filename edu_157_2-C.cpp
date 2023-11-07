//11/4/2023
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

int solve(){
    int N;
    int ans=0;
    cin >> N;
    vector<vector<int>> has(6, vector<int>(1000, 0));
    vector<string> vect(N);
    for(int i=0; i<N; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end(), [](const string& a, const string& b){
        return a.length() < b.length();
    });
    //for(const auto& str : vect)
    //    cout << str << " ";
    //cout << "\n";
    int n;
    for(const auto& str : vect){
        n = str.length();
        int sum=0;
        for(auto c : str)
            sum += c-'0';
        if(n%2 == 0){
            int sum1=0, sum2=0, sum3=0, sum4=0;
            for(int i=0; i<n/2-1; i++)
                sum1 -= str[i]-'0';
            for(int i=n/2-1; i<n; i++)
                sum1 += str[i]-'0';
                
            for(int i=0; i<n/2+1; i++)
                sum2 += str[i]-'0';
            for(int i=n/2+1; i<n; i++)
                sum2 -= str[i]-'0';

            for(int i=0; i<max(n/2-2, 0LL); i++)
                sum3 -= str[i]-'0';
            for(int i=max(n/2-2, 0LL); i<n; i++)
                sum3 += str[i]-'0';

            for(int i=0; i<min(n/2+2, n); i++)
                sum4 += str[i]-'0';
            for(int i=min(n/2+2, n); i<n; i++)
                sum4 -= str[i]-'0';
            sum1 = max(sum1, 0LL);
            sum2 = max(sum2, 0LL);
            sum3 = max(sum3, 0LL);
            sum4 = max(sum4, 0LL);
            //cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << "\n";      
            ans += has[2][sum1] + has[2][sum2] + has[4][sum3] + has[4][sum4];
        }
        else{
            int sum1=0, sum2=0, sum3=0, sum4=0, sum5=0, sum6=0;
            for(int i=0; i<n/2; i++)
                sum1 -= str[i]-'0';
            for(int i=n/2; i<n; i++)
                sum1 += str[i]-'0';

            for(int i=0; i<n/2+1; i++)
                sum2 += str[i]-'0';
            for(int i=n/2+1; i<n; i++)
                sum2 -= str[i]-'0';

            for(int i=0; i<max(n/2-1, 0LL); i++)
                sum3 -= str[i]-'0';
            for(int i=max(n/2-1, 0LL); i<n; i++)
                sum3 += str[i]-'0';

            for(int i=0; i<min(n/2+2, n); i++)
                sum4 += str[i]-'0';
            for(int i=min(n/2+2, n); i<n; i++)
                sum4 -= str[i]-'0';

            for(int i=0; i<max(n/2-2, 0LL); i++)
                sum5 -= str[i]-'0';
            for(int i=max(n/2-2, 0LL); i<n; i++)
                sum5 += str[i]-'0';

            for(int i=0; i<min(n/2+3, n); i++)
                sum6 += str[i]-'0';
            for(int i=min(n/2+3, n); i<n; i++)
                sum6 -= str[i]-'0';
            
            sum1 = max(sum1, 0LL);
            sum2 = max(sum2, 0LL);
            sum3 = max(sum3, 0LL);
            sum4 = max(sum4, 0LL);
            sum5 = max(sum5, 0LL);
            sum6 = max(sum6, 0LL);

            //cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " " << sum5 << " " << sum6 << "\n";
            ans += has[1][sum1] + has[1][sum2] + has[3][sum3] + has[3][sum4] + has[5][sum5] + has[5][sum6];
        }
        has[n][sum]++;
        ans++;
    }
    return ans;
}

signed main(){
    Anemoi
    int n = 1;
    for(int i=0; i<n; i++)
        cout << solve() << "\n";
}