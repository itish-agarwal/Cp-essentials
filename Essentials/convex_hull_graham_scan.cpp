#include <bits/stdc++.h>

using namespace std;
#define int long long 

struct pt {
  int x, y;
  pt(int xx, int yy) {
    x = xx;
    y = yy;
  }
};  
bool cmp(pt a, pt b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cw(pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
void convex_hull(vector<pt>& a) {
  if((int)a.size() == 1)
    return;
  int n = a.size();
  sort(a.begin(), a.end(), &cmp);
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for(int i = 1; i < n; i++) {
    if(i == n - 1 || cw(p1, a[i], p2)) {
      while((int)up.size() >= 2 && !cw(up[(int)up.size() - 2], up.back(), a[i])) {
        up.pop_back();
      }
      up.push_back(a[i]);
    }
    if(i == n - 1 || ccw(p1, a[i], p2)) {
      while((int)down.size() >= 2 && !ccw(down[(int)down.size() - 2], down.back(), a[i])) {
        down.pop_back();
      }
      down.push_back(a[i]);
    }
  }
  a.clear();
  for(int i = 0; i < (int)up.size(); i++) 
    a.push_back(up[i]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, H;
    cin >> N >> H;
    vector<pt> points;
    points.push_back(pt(0, H));
    vector<int> x(N), h(N);
    for(int i = 0; i < N; i++)
      cin >> x[i];
    for(int i = 0; i < N; i++)
      cin >> h[i];

    for(int i = 0; i < N; i++)
      points.push_back(pt(x[i], h[i]));

    convex_hull(points);

    x.clear();
    h.clear();
    for(auto it : points) {
      x.push_back(it.x);
      h.push_back(it.y);
    }
    bool ok = true;
    int ans = 0;
    N = x.size();

    auto compute = [&](int cur_x, int& cur_h, int next_x, int next_h) {
      int max_can_reach = cur_h + next_x - cur_x;
      if(max_can_reach <= next_h) {
        ok = false;
        return;
      }

      int total = next_x - cur_x, lo = 0, hi = 2e14 + 7, req = hi;

      while(lo <= hi) {
        int mid = (lo + hi) / 2;  
        if(cur_h + 2 * mid - total > next_h) {
          req = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      } 
      ans += req;
      cur_h = cur_h + 2 * req - total;
    };

    int cur_h = H, cur_x = 0;
    for(int i = 1; i < N; i++) {
      compute(cur_x, cur_h, x[i], h[i]);
      cur_x = x[i];
    }
    cout << (ok ? ans : -1) << '\n';
  }
  return 0;
}