#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0, s = 0;
    int tail = 0, head = -1;
    while(tail < n) {
      while(head+1 < n && s+a[head+1] <= k) {
        head++;
        s += a[head];
      }
      ans += head-tail+1;
      if(head >= tail) {
        s -= a[tail];
      } else {
        head++;
      }
      tail++;
    }
    cout << ans << '\n';
  }
  return 0;
}
