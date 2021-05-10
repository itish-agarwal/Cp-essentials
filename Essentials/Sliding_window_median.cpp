#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree <int,  null_type,  less_equal<int>,  rb_tree_tag,  tree_order_statistics_node_update>

/* 
less<int> -> acts as set
less_equal<int> -> acts as multiset
*/

/*
order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ordered_set s;

  for(int i = 0; i < k; i++) {
    s.insert(a[i]);
  }

  vector<int> ans;
  int x = *s.find_by_order(k/2 + k%2 - 1);

  ans.push_back(x);

  for(int i = k; i < n; i++) {
    s.erase(s.find_by_order(s.order_of_key(a[i - k]))); // erase element from multiset
    s.insert(a[i]);

    x = *s.find_by_order(k/2 + k%2 - 1);
    ans.push_back(x);
  }

  for(int t : ans) {
    cout << t << " ";
  }
  cout << '\n';
  return 0;
}