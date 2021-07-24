#include <bits/stdc++.h>

using namespace std;
const int M = 32;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 

  //default constructor -> initializes all bits with 0
  bitset<M> bs1;

  //bs2 is initialized with bits of 20
  bitset<M> bs2(3);
  cout << bs2 << endl;
  // for(int bit = 0; bit < 32; bit++)
  //   cout << bs2[bit] << " ";

  //bs3 is initialized with bits of string
  bitset<M> bs3(string("1100"));
  cout << bs3 << endl;


  //count returns number of set bits 
  cout << bs3.count() << endl;

  //test function returns 1 if bit is set
  for(int i = 0; i < bs3.size(); i++) {
    cout << bs3.test(i) ;
  }
  cout << endl;


}