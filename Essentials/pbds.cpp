
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <int,  null_type,  less<int>,  rb_tree_tag,  tree_order_statistics_node_update>
#define int int64_t

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x, y;
    cin >> n >> x;
    int in = 0;
    ordered_set s;
    for(int i = 0; i < n; i++) {
      cin >> y;
      in += i - s.order_of_key(y);
      s.insert(y);
    }
    cout << 2*in*x << '\n';
  }
  return 0;
}
