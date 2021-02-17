#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 1; i <= 100; i++) {
    int ans = 0;
    for(int j = 1; j <= i; j++) {
      if(2*j+1 == i) {
        ++ans;
      }
    }
    cout << i << " - " << ans << '\n';
  }
  return 0;
}
