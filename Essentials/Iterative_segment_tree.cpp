#include <bits/stdc++.h>

using namespace std;
#define int long long 

vector<int> tree;

int query(int id, int l, int r, int lq, int rq) {
  if(lq > r || l > rq) {
    return 0;
  }
  if(lq <= l && r <= rq) {
    return tree[id];
  }
  int mid = (l + r)/2;
  return query(2*id, l, mid, lq, rq) + query(2*id+1, mid+1, r, lq, rq);
}

void update(int i, int v, int n) {
  tree[n + i] = v; // modifying the leaf
  // updating everything on the path to the roof
  for(int j = (n + i) / 2; j >= 1; j /= 2) {
    tree[j] = tree[2*j] + tree[2*j + 1];
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  while(__builtin_popcount(n) != 1) {
    a.push_back(0);
    n += 1;
  }
  
  tree.resize(2 * n);
  
  for(int i = 0; i < n; i++) {
    tree[n + i] = a[i];
  }
  
  for(int i = n - 1; i >= 1; i--) {
    tree[i] = tree[2*i] + tree[2*i + 1];
  }
  
  while(q--) {
    int tt;
    cin >> tt;
    if(tt == 1) {
      int i, v;
      cin >> i >> v;
      --i;
      update(i, v, n);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << query(1, 0, n - 1, l, r) << '\n';
    }
  }
}

