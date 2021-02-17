#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set; 

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int q, x;
    cin >> q;
    new_data_set s;
    while(q--) {
      string op;
      cin >> op >> x;
      if(op=="add"){
        if(s.find(x)==s.end()) {
          s.insert(x);
        }
      } else if(op=="remove") {
        if(s.find(x)!=s.end()) {
          s.erase(x);
        }
      } else if(op=="find") {
        if((int)s.size() <= x) {
          cout << "-1\n";
        } else {
          cout << *s.find_by_order(x) << '\n';
        }
      } else {
        if(s.find(x)!=s.end()) {
          cout << s.order_of_key(x) << '\n';
        } else {
          s.insert(x);
          cout << s.order_of_key(x) << '\n';
          s.erase(x);
        }
      }
    }
  }
  return 0;
}

