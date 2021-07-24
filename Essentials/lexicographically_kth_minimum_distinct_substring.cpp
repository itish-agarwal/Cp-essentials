#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
struct SuffixArray {
  string S;
  int N;
  vector<int> p, c, lcp;
  //lcp[i] -> value of longest common prefix of two
  //suffixes S[p[i]...N-1] and S[p[i + 1]....N-1];
  
  //TODO: check if default symbol works or change it
  SuffixArray(string s) {
    S = s;
    S += "!";
    N = S.size();
    p.resize(N);
    c.resize(N);
    lcp.resize(N);
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
  void build_lcp_array() {
    int k = 0;
    //number of characters that we already know are matching
    for(int i = 0; i + 1 < N; i++) {
      //pi is position of suffix i in suffix array
      //c is already the inverse permutation of p;
      int pi = c[i];
 
      //find previous suffix in suffix array
      int j = p[pi - 1];
 
      //find lcp of suffixes starting from i and j
      while(S[i + k] == S[j + k])
        k++;
 
      lcp[pi - 1] = k;
 
      //get to next suffix
      k = max(0LL, k - 1);
    }
  }
  int number_of_different_substrings() {
    build_suffix_array();
    build_lcp_array();
    int ans = 0;
    for(int i = 0; i + 1 < N; i++)
      ans += lcp[i];
    return N*(N - 1)/2 - ans;
  }
  vector<int> get_suffix_array() {
    return p;
  }
  vector<int> get_lcp_array() {
    return lcp;
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  string S;

  int qq, K;
  cin >> S >> qq;

  SuffixArray suff(S);
 
  suff.build_suffix_array();
  suff.build_lcp_array();
 
  vector<int> p = suff.get_suffix_array();
  vector<int> lcp = suff.get_lcp_array();

  int N = S.size();

  for(int q = 0; q < qq; q++) {
    cin >> K;   
    for(int i = 0; i <= N; i++) {
      int substrings = N - p[i] - (i > 0 ? lcp[i - 1] : 0);
      if(substrings >= K) {
        int len = (i > 0 ? lcp[i - 1] : 0) + K;
        cout << S.substr(p[i], len) << '\n';
        break;
      } else {
        K -= substrings;
      }
    }
  }
  return 0;
}