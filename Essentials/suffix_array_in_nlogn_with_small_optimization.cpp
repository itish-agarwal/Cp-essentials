//Now we have nlogn code
//To optimize slightly more->
//from k->k+1, build strings of length 2^(k+1)
//such that they are already sorted by 2nd halves of pairs
#include <bits/stdc++.h>

using namespace std;

struct Suffix_array {
  string S;
  int N;
  vector<int> p, c;
  Suffix_array(string s) {
    S = s;
    S += "$";
    N = S.size();
    p.resize(N);
    c.resize(N);
  }
  void counting_sort() {
    //sort array p by values in array c
    vector<int> cnt(N);
    for(auto it : c) 
      cnt[it] += 1;

    vector<int> p_new(N);
    //split new array into buckets
    //find index of next element of each bucket
    vector<int> pos(N);
    // pos[i]->first empty element in bucket number i
    for(int i = 1; i < N; i++) {
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for(auto it : p) {
      int bucket = c[it];
      p_new[pos[bucket]] = it;
      pos[bucket] += 1;
    }
    p = p_new;
  }
  void build_suffix_array() {
    //iteration 0
    {
      vector<pair<char, int>> x(N);
      for(int i = 0; i < N; i++)
        x[i] = {S[i], i};

      sort(x.begin(), x.end());

      for(int i = 0; i < N; i++)
        p[i] = x[i].second;
      c[p[0]] = 0;
      for(int i = 1; i < N; i++) {
        if(x[i].first == x[i - 1].first)
          c[p[i]] = c[p[i - 1]];
        else 
          c[p[i]] = c[p[i - 1]] + 1;
      }
    }

    int k = 0;
    while((1 << k) < N) {
      for(int i = 0; i < N; i++) 
        p[i] = (p[i] - (1 << k) + N) % N;

      counting_sort();

      vector<int> c_new(N);
      c_new[p[0]] = 0;
      for(int i = 1; i < N; i++) {
        pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]};
        pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % N]};
        if(prev == now) 
          c_new[p[i]] = c_new[p[i - 1]];
        else
          c_new[p[i]] = c_new[p[i - 1]] + 1;
      }
      c = c_new;
      k++;
    }
  }
  vector<int> get_suffix_array() {
    return p;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  Suffix_array p(s);

  p.build_suffix_array();
  vector<int> a = p.get_suffix_array();

  for(int i = 0; i <= (int)s.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  return 0;
}