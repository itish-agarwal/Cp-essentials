#include <bits/stdc++.h>

using namespace std;

void test_case() {
  int k, a, b, ans = 0;
  cin >> k >> a >> b;
  int d = a / b;
  for(int i = 0; i < k + 1; i++) {
    if(i > 0) ans += d;
    // cout << d;
    a = a - (b * d);
    if(a == 0) break;
    a *= 10;
    d = a / b;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
