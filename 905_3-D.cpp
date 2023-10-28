//2023/10/28
#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main()
{
  Anemoi
  int n;
  cin >> n;
  multiset<int> L, R;
  for(int i=0; i<n; i++){
    char c;
    cin >> c;
    int l, r;
    cin >> l >> r;
    if(c == '+'){
      L.insert(l);
      R.insert(r);
    }
    else{
      L.erase(L.find(l));
      R.erase(R.find(r));
    }

    if(L.size() <= 1){
      cout << "NO\n";
    }
    else{
      auto i = R.begin();
      auto j = L.end();
      j--;
      if(*i < *j)
        cout << "YES\n";
      else
        cout << "NO\n";
    }

  }
  return 0;
}