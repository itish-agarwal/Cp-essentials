//Count the number of times a given word w occurs in s

/*Let p be the node in the automaton that we end up 
while running it for w. This time the number of times 
a given word occurs is the number of paths starting 
from p and ending in a terminal node, so one can
 calculate recursively the number of paths from each 
 node ending in a terminal node
 */
#include <bits/stdc++.h>
 
using namespace std;
 
struct state {
  int len, link;
  map<char, int> next;
};
 
const int nax = 3e3 + 5;
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
  int N, Q;
  cin >> N >> Q >> S;

  sa_init();
  for(char ch : S)
    sa_extend(ch);

  vector<int> terminal(sz + 1);
 
  int p = last;
  while(p != -1) {
    terminal[p] = 1;
    p = st[p].link;
  }

  vector<int> dp(sz + 1, -1);
 
  function<int(int)> rec = [&](int x) {
    if(dp[x] > -1)
      return dp[x];
    int res = terminal[x];
    for(char ch = 'a'; ch <= 'z'; ch++) {
      if(st[x].next.count(ch) > 0) 
        res += rec(st[x].next[ch]);
    }
    return dp[x] = res;
  };

  for(int q = 0; q < Q; q++) {
    string p;
    cin >> p;

    bool ok = true;
    int last = 0;
    for(char ch : p) {
      if(st[last].next.count(ch) == 0) {
        ok = false;
        break;
      }
      last = st[last].next[ch];
    }
    cout << (ok ? rec(last) : 0) << '\n';
  }
  return 0;
}