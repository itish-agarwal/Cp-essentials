#include <bits/stdc++.h>

using namespace std;
#define int long long
const int nax = 1e6 + 777;

int ceil(int a, int b) {
  return (a + b - 1)/b;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int L, R;
  cin >> L >> R;
  vector<int> ispr(nax, 1);
  ispr[1] = false;
  for(int p = 2; p*p <= R; p++) {
    if(ispr[p]) {
      for(int i = p+p; i*i <= R; i += p) {
        ispr[i] = false;
      }
    }
  }
  vector<int> pr(R - L + 1, 1);
  for(int p = 2; p*p <= R; p++) {
    if(ispr[p]) {
      for(int strike = p*ceil(L, p); strike <= R; strike += p) {      
        if(p^strike) {
          pr[strike-L] = false;
        }
      }
    }
  }
  vector<int> ans;
  for(int i = 0; i < (int)pr.size(); i++) {
    if(pr[i] && i+L > 1) {
      ans.push_back(i + L);
    }
  }
  cout << (int)ans.size() << '\n';
  for(int x : ans) {
    cout << x << " ";
  }
  cout << '\n';
  return 0;
}
