#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std; 

#define int cpp_int

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
      ans *= i;
    }
    cout << ans << '\n';
  }
}
