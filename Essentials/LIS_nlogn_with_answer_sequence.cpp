//vector<int> indices
// indices[i] -> index of "smallest" number that comes at 
// the end of LIS of length i

//vector<int> sequences (parent array)

//index[1] -> index of smallest number that can come at end of 
//LIS of length 1

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> sequences(n, -1), indices(n + 1, -1);
  int length = 0;

  auto binary_search = [&](int num) {
    if(length < 1) {
      return 1;
    }
    int lo = 1, hi = length;
    while(lo <= hi) {
      int mid = (lo + hi)/2;
      if(a[indices[mid]] < num) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  };

  for(int i = 0; i < n; i++) {
    int nl = binary_search(a[i]);
    sequences[i] = indices[nl - 1];
    indices[nl] = i;
    length = max(length, nl);
  }

  vector<int> LIS;
  int in = indices[length];

  LIS.push_back(a[in]);
  while(sequences[in] > -1) {
    LIS.push_back(a[sequences[in]]);
    in = sequences[in];
  }

  cout << length << endl;

  reverse(LIS.begin(), LIS.end());
  for(int x : LIS) {
    cout << x << " ";
  }
  cout << '\n';
}

  