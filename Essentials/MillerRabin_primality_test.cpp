#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 power(u64 a, u64 b, u64 mod) {
  //TODO: take care of long long
  u64 res = 1;
  a %= mod;
  while(b > 0) {
    if(b % 2)
      res = ((u128)res * a) % mod;
    a = ((u128)a * a) % mod;
    b >>= 1;
  }
  return res;
}
bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = power(a, d, n);
  if(x == 1 || x == n - 1)
    return false;
  for(int r = 1; r < s; r++) {
    x = ((u128) x * x) % n;
    if(x == n - 1)
      return false;
  }
  return true;
}
bool MillerRabin(u64 n, int iter = 15) {
  if(n < 4)
    return n == 2 || n == 3;
  int s = 0;
  u64 d = n - 1;
  while((d & 1) == 0) {
    d >>= 1;
    s++;
  }

  for(int i = 0; i < iter; i++) {
    int a = 2 + rand() % (n - 3);
    if(check_composite(n, a, d, s))
      return false;
  }

  return true;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while(tests--) {
    u64 n;
    cin >> n;
    cout << (MillerRabin(n) ? "YES" : "NO") << '\n';
  }
}