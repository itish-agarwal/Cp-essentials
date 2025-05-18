//https://www.naukri.com/code360/problems/complete-string_2687860?interviewProblemRedirection=true&practice_topic%5B%5D=Tries&count=25&page=4&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION&customSource=studio_nav

//A string is called a complete string if every prefix of this string 
// is also present in the array ‘A’. Ninja is challenged to find 
// the longest complete string in the array ‘A’.If there are multiple
//  strings with the same length, return the lexicographically 
//  smallest one and if no string exists, return "None".

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

    bool insert(string word) {
        Node *current = root;
        bool res = true;
        int sz = 0;
        for (char ch : word) {
            sz++;
            int x = ch - 'a';

            if (!current -> links[x]) 
                current -> links[x] = new Node();

            current = current -> links[x];

            if (current -> end_count == 0 && sz < (int) word.size())
                res = false;
            
            current -> prefix_count++;
        }

        current -> end_count++;
        return res;
    }
};

string completeString(int n, vector<string> &a){
    sort(a.begin(), a.end());

    string best = "";
    Trie *trie = new Trie();

    for (string s : a) {
        bool good = trie -> insert(s);
        if (good) {
            if ((int) s.size() > (int) best.size())
                best = s;
        }
    }

    return best.empty() ? "None" : best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string>a={"n","ni","nin","ninj","ninja","ninga"};
    cout<<completeString(6,a)<<endl;
}