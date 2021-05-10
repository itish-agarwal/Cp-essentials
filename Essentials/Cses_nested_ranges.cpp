#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    //initialise t
    t.assign(4*_n, INF);
  }
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    //update t[id] here;
    t[id] = min(t[2*id], t[2*id+1]);
  }
  //change return type of query if wanted
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) return INF;//see to this
    if(lq <= l && r <= rq) return t[id];
    int mid = (l + r)/2;
    int L = query(2*id, l, mid, lq, rq);
    int R = query(2*id+1, mid+1, r, lq, rq);
    return min(L, R);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<tuple<int, int, int>> intervals;

  for(int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    intervals.emplace_back(l, -r, i);
  }
  sort(intervals.begin(), intervals.end());

  segtree tree(n);
  for(int i = 0; i < n; i++) {
    tree.update(1, 0, n - 1, i, -get<1>(intervals[i]));
  }

  vector<int> left(n);
  for(int i = 0; i < n; i++) {
    left[i] = get<0>(intervals[i]);
  }

  vector<int> contains(n);
  for(int i = 0; i < n; i++) {
    int in = upper_bound(left.begin(), left.end(), -get<1>(intervals[i])) - left.begin() - 1;
    //find min in i.....in
    if(in >= i + 1) {
      int mn = tree.query(1, 0, n - 1, i + 1, in);
      if(mn <= -get<1>(intervals[i])) {
        contains[get<2>(intervals[i])] = 1;
      }
    }
  }  

  vector<int> contained(n);
  segtree tree_max(n);
  for(int i = 0; i < n; i++) {
    tree_max.update(1, 0, n - 1, i, get<1>(intervals[i]));
  }
  for(int i = 1; i < n; i++) {
    int mx = -tree_max.query(1, 0, n - 1, 0, i - 1);
    if(mx >= -get<1>(intervals[i])) {
      contained[get<2>(intervals[i])] = 1;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i > 0) {
      cout << " ";
    }
    cout << contains[i];
  }
  cout << '\n';
  for(int i = 0; i < n; i++) {
    if(i > 0) {
      cout << " ";
    }
    cout << contained[i];
  }
  cout << '\n';
  return 0;
}
