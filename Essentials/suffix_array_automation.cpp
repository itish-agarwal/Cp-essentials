#include <bits/stdc++.h>
 
using namespace std;
 
struct state {
  int len, link;
  map<char, int> next;
};
 
const int nax = 1e5 + 5;
state st[2 * nax];
int sz, last;
 
//initialize the suffix automation
void sa_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}
 
void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
 
  while(p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
 
  if(p == -1) {
    st[cur].link = 0;
  }
  else {  
    int q = st[p].next[c];
    if(st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while(p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  string S;
  cin >> S;
  int N = S.size();

  sa_init();
  for(char ch : S)
    sa_extend(ch);
  
  int Q;
  cin >> Q;
  for(int q = 0; q < Q; q++) {
    string P;
    cin >> P;
    bool is_substring = true;
    int last = 0;
    for(char ch : P) {
      if(st[last].next.find(ch) == st[last].next.end()) {
        is_substring = false;
        break;
      }
      last = st[last].next[ch];
    } 

    cout << (is_substring ? "Y" : "N") << '\n';
  }
  return 0;

}