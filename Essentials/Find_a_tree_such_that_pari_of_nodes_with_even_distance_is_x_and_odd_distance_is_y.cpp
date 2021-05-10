#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y;
    cin >> x >> y;
    int n = sqrt(x + y);
    if(n*n != x + y) {
      cout << "NO\n";
    } else {
      int even = 1, odd = n - 1;
      while(odd >= 1) {
        if(2*even*odd == y) {
          break;
        }
        even += 1;
        odd -= 1;
      }
      if(odd > 0) {
        cout << "YES\n" << n << '\n';
        for(int i = 0; i < odd; i++) {
          cout << 1 << " " << i + 2 << '\n';
        } 
        for(int i = 1; i < even; i++) {
          cout << 2 << " " << odd + i + 1 << '\n';
        }
      } else {
        cout << "NO\n";
      }
    }
  }
}