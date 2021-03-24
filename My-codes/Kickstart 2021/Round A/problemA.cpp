#include <bits/stdc++.h>
 
using namespace std;

void test_case() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int c = 0;
  for(int i = 0; i < n / 2; ++i) {
    if(s[i] != s[n-1-i]) {
      ++c;
    }
  }
  cout << abs(k-c) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    cout << "Case #" << nr << ": ";
    test_case();
  }
}
