#include <bits/stdc++.h>
 
using namespace std;

//segment tree which finds index of k-th one in an array
struct segtree {
  vector<int> t;
  segtree(int n) {
    t.resize(4*n);
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
    t[id] = t[2*id] + t[2*id+1];
  }
  int sum_q(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) return 0;
    if(lq<=l && r<=rq) return t[id];
    int mid = (l + r)/2;
    return sum_q(2*id, l, mid, lq, rq) + sum_q(2*id+1, mid+1, r, lq, rq);
  }
  int query(int id, int l, int r, int lq, int rq, int k) {
    if(t[id] < k) return -1;
    if(l == r) return l;
    int mid = (l + r)/2;
    int on_left = sum_q(2*id, l, mid, lq, rq);
    if(on_left >= k) {
      return query(2*id, l, mid, lq, rq, k);
    }
    return query(2*id+1, mid+1, r, lq, rq, k - on_left);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  
  
  
}
    
  
