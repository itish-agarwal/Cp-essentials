#include "bits/stdc++.h"
using namespace std;
const int BITS = 31;

struct Node {
    Node* child[2];
    int cnt;

public:
    Node() {
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};

class BitTrie {
    Node *root;
    int B;

public:
    BitTrie(int bits) {
        root = new Node();
        B = bits;
    }

    void insert(const int& x) {
        Node *current = root;
        for (int b = B; b >= 0; --b) {
            int p = (x & (1 << b)) ? 1 : 0;
            if (!current -> child[p])
                current -> child[p] = new Node();

            current = current -> child[p];
            current -> cnt++;
        }
    }

    void erase(const int& x) {
        // assumes number is present in trie.
        Node *current = root;
        for (int b = B; b >= 0; --b) {
            int p = (x & (1 << b)) ? 1 : 0;
            current = current -> child[p];
            current -> cnt--;
        }
    }

    int max_xor(const int& x) {
        Node *current = root;
        int ans = 0;

        for (int b = B; b >= 0; --b) {
            int p = (x & (1 << b)) ? 1 : 0;
            if (current -> child[1^p] && current -> child[1^p] -> cnt > 0) {
                ans += 1 << b;
                current = current -> child[1^p];
            }
            else {
                if (current -> child[p]) 
                    current = current -> child[p];
                else
                    return ans;
            }
        }

        return ans;
    }

    int xor_less_than_k(const int& x, const int& k) {
        // returns number of numbers in the trie s.t. {num}^y < k
        int ans = 0;
        Node *current = root;

        for (int b = B; b >= 0; --b) {
            if (!current)
                break;

            if (x & (1 << b)) {
                if (k & (1 << b)) {
                    ans += (current -> child[1] ? current -> child[1] -> cnt : 0);
                    current = current -> child[0];
                }
                else {
                    current = current -> child[1];
                }
            }
            else {
                if (k & (1 << b)) {
                    ans += (current -> child[0] ? current -> child[0] -> cnt : 0);
                    current = current -> child[1];
                }
                else{
                    current = current -> child[0];
                }
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;

    while (tests-- > 0) {
        int N, K;
        cin >> N >> K;

        BitTrie *trie = new BitTrie(BITS);
        trie -> insert(0);

        long long ans = 0;
        int run_xor = 0;

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            run_xor ^= x;

            ans += trie -> xor_less_than_k(run_xor, K);
            trie -> insert(run_xor);
        }

        cout << ans << '\n';
    }
}