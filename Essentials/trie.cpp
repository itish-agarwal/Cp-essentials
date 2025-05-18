#include "bits/stdc++.h"
using namespace std;
const int ALPHABET = 26;

struct Node {
    vector<Node*> links;
    bool flag = false;

public:
    Node() {
        links.assign(ALPHABET, NULL);
    }
};

class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current->links[x])
                current -> links[x] = new Node();

            current = current->links[x];
        }

        current->flag = true;
    }

    bool search(string word) {
        Node *current = root;
        for (char ch : word) {
            int x = ch - 'a';
            if (!current -> links[x]) 
                return false;

            current = current -> links[x];
        }

        return current -> flag;
    }

    bool startsWith(string prefix) {
        Node *current = root;
        for (char ch : prefix) {
            int x = ch - 'a';
            if (!current -> links[x])
                return false;

            current = current -> links[x];
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple")<<endl;
}