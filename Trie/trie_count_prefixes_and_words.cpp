//Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

//1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

//2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

//3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

//4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

//5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

#include "bits/stdc++.h"
using namespace std;
const int ALPHABET = 26;

struct Node {
    vector<Node*> links;
    int prefix_count, end_count;

public:
    Node() {
        links.assign(ALPHABET, NULL);
        prefix_count = end_count = 0;
    }
};

class Trie{
    Node *root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current -> links[x]) 
                current -> links[x] = new Node();

            current = current -> links[x];
            current -> prefix_count++;
        }

        current -> end_count++;
    }

    int countWordsEqualTo(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current -> links[x])
                return 0;

            current = current -> links[x];
        }

        return current -> end_count;
    }

    int countWordsStartingWith(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current -> links[x])
                return 0;

            current = current -> links[x];
        }

        return current -> prefix_count;
    }

    void erase(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current -> links[x])
                return;

            current = current -> links[x];
            current -> prefix_count--;
        }

        current -> end_count--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Trie *t = new Trie();
    t->insert("coding");
    t->insert("ninja");
    cout<<t->countWordsEqualTo("coding")<<endl;
    cout<<t->countWordsStartingWith("nin")<<endl;
    t->erase("coding");
    cout<<t->countWordsEqualTo("coding")<<endl;
    cout<<t->countWordsStartingWith("cod")<<endl;
    cout<<t->countWordsStartingWith("n")<<endl;
}