#include <bits/stdc++.h>

using namespace std;

/* STRING TRIES 

struct node {
  vector<node*> child;
  node() {
    child.assign(26, NULL);
  }
  //use map if character set is unsure
  int prefix;

  //for a node, prefix stores number of strings
  //having path till now as their prefix

  vector<string> wend;
  //at this particular node, how many strings end
};

struct trie {
  node* t;
  // node t is the root, represents full trie
  trie() {
    t = new node;
  }....

  void insert(string s) { // O(length(S))
    node* cur = t;
    for(char ch : s) {
      cur->prefix += 1;
      int x = ch - 'a';
      if(cur->child[x] == NULL) {
        cur -> child[x] = new node();
      }
      cur = cur -> child[x];
    }
    cur -> wend.push_back(s);
  }

  //delete a string from the trie
  //do not delete any nodes/paths
  //just do : follow the path corresponding to
  //the string, do cur->prefix-- and at the end
  //node, erase string from wend
};

*/


/* 
APPLICATION 1

From a set of strings, answer Q queries:
? S K -> Find the lexicographically smallest top K results for
         prefix match of S

Eg -> aa, aac, acd, cd
If S = "a" and K = 2, return aa, aac

Solution:-
Build a preffix trie

*/







/* BIT TRIES

stuct node {
  vector<node*> child;
  int cnt = 0; //how many numbers lie in leaves of this subtree
  node() {
    child.assign(2, NULL);
  }
};

stuct trie {
  node* t; //root;
  trie() {
    t = new node();
  }
  
  void inset(int n) {  //O(length(binary representation))
    node* cur = t;
    for(int i = LN - 1; i >= 0; i--) {
      cur -> cnt += 1;
      int x = (n & (1 << i) ? 1 : 0);
      if(cur -> child[x] == NULL) {
        cur -> child[x] = new node();
      }
      cur = cur -> child[x];
    }
    cur -> cnt += 1;
    cur -> wend.push_back(n);
  }
}
  

*/








int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);


}