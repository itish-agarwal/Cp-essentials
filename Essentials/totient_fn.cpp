#include <bits/stdc++.h>

using namespace std;
#define int long long

void eulerPhi(int n) {
  int phi[n + 1];
  for(int i = 1; i <= n; ++i) phi[i] = i;
  for(int i = 2; i <= n; ++i) {
    if(phi[i] == i) {
      phi[i] = i - 1;
      for(int p = i + i; p <= n; p++) {
        phi[i] *= (p-1);
        phi[i] /= p;
      }
    }
  }
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, ans;
    cin >> n;
    ans = n;
    for(int p = 2; p*p <= n; p++) {
      if(n%p == 0) {
        ans /= p;
        ans *= (p-1);
        while(n%p == 0) {
          n /= p;
        }
      }
    }
    if(n > 1) {
      ans /= n;
      ans *= (n-1);
    }
    cout << ans << '\n';
  }
  return 0;
}
