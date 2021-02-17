#include <bits/stdc++.h>

using namespace std;
#define int long long

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
