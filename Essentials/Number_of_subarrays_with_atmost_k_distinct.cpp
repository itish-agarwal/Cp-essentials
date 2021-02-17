#include <bits/stdc++.h>

using namespace std;
const int nax = 1e6 + 777;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, distinct = 0;
    cin >> n >> k;
    vector<int> a(n), cnt(nax);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto insert = [&](int x) {
      cnt[x]++;
      if(cnt[x] == 1) {
        distinct++;
      }
    };
    auto remove = [&](int x) {
      cnt[x]--;
      if(cnt[x] == 0) {
        distinct--;
      }
    };
    int tail = 0, head = -1;
    long long answer = 0;
    while(tail < n) {
      while(head+1 < n && ((distinct<k && cnt[a[head+1]]==0) || (distinct<=k && cnt[a[head+1]]>0))) {
        head++;
        insert(a[head]);
      }
      answer += max(0, head-tail+1);
      if(head < tail) {
        head = tail-1;
      } else {
        remove(a[tail]);
      }
      tail++;
    }
    cout << answer << '\n';
  }
  return 0;
}
