#include <bits/stdc++.h>

using namespace std;
const int nax = 1e5 + 66;

struct segtree {
  vector<int> t;
  segtree(int n = nax) {
    t.resize(4*n);
    for(int& x : t) {
      x = -1;
    }
  } 

  void push(int id, int l, int r) {
    if(t[id] > -1) {
      if(l!=r) {
        t[2*id] = t[2*id+1] = t[id];
        t[id] = -1;
      }
    }
    return;
  }
  void update(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if(lq>r || l>rq) {
      return;
    }
    if(lq<=l && r<=rq) {
      t[id] = val;
      push(id, l, r);
      return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, lq, rq, val);
    update(2*id+1, mid+1, r, lq, rq, val);
  }
  int query(int id, int l, int r, int pos) {
    push(id, l, r);
    if(l == r) {
      return t[id];
    }
    int mid = (l+r)/2;
    if(pos <= mid) {
      return query(2*id, l, mid, pos);
    }
    return query(2*id+1, mid+1, r, pos);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q, x;
  cin >> n >> q;
  segtree tree(n);
  while(q--) {
    int op;
    cin >> op;
    if(op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      --r;
      tree.update(1, 0, n-1, l, r, v);
    } else {
      int i;
      cin >> i;
      cout << max(0, tree.query(1, 0, n-1, i)) << '\n';
    }
  }
  return 0;
}