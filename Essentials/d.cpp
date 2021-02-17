#include <bits/stdc++.h>

using namespace std;
#define int int64_t

bool is(string s) {
  for(int i = 1; i < (int)s.size(); i++) {
    if(abs(s[i]-s[i-1]) > 1) {
      return 0;
    }
  }
  return 1;
}
set<string> s;
void fill(string t) {
  if(s.size() > 10) {
    return;
  }
  char lst = t.back();
  s.insert(t);
  if(lst >= '1') {
    char app = lst - 1;
    t += app;
    fill(t);
    t.pop_back();
  }
  if(lst < '9') {
    char app = lst + 1;
    t += app;
    fill(t);
    t.pop_back();
  }
  
  return;
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(char ch = '1'; ch <= '9'; ch++) {
    string s = "";
    s += ch;
    fill(s);
  }
  for(string str : s) {
    cout << str << '\n';
  }
}
  
