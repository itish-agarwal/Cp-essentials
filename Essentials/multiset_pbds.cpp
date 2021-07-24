#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> struct PBDS{
int timer;
tree<pair<T,int>, null_type, less<pair<T,int> >, rb_tree_tag, tree_order_statistics_node_update> tt;
PBDS(){timer = 0;}
int szz(){return int(tt.size());}
void insert(T x){tt.insert(MP(x, timer));timer++;}
int lower(T x){return tt.order_of_key(MP(x, -1));}//<
T kth(int a){return (*tt.find_by_order(a)).F;}// Zero indexed
void del(T x) {pair<T,int> tmp = (*tt.find_by_order(lower(x)));tt.erase(tmp);
}//make sure x exists
int higher(T x){int tmp = lower(x);return (int(tt.size()) - tmp);}//>=
}; 
int main() {

}