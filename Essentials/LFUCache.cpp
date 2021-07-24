#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity, size, lfu = 0;
    unordered_map<int, list<int>> keys; //(frequency->all keys map)
    unordered_map<int, pair<int, int>> values; //(key -> {value, frequency})
    unordered_map<int, list<int>::iterator> iters;
    void update(int key) { // update a key
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq+1].push_back(key);
        iters[key] = --keys[freq+1].end();
        if(keys[lfu].empty())
            lfu++;
    }
public:

    LFUCache(int n) {
        capacity = n;
        size = 0;
    }

    int get(int key) {
        if(values.find(key) == values.end())
            return -1;
        update(key);
        return values[key].first;
    }

    void put(int key, int val) {
        if(!capacity)
            return;
        if(values.find(key) != values.end()) {
            values[key].first = val;
            update(key);      
        } else {
            if(size == capacity) {
            int evict = keys[lfu].front();
            keys[lfu].pop_front();
            values.erase(evict);
            iters.erase(evict);
        } else {
            size++;
        }
        values[key] = {val, 1};
        keys[1].push_back(key);
        iters[key] = --keys[1].end();
        lfu = 1;
    }
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    LFUCache* obj = new LFUCache(n);
    while (q--) {
        string op;
        cin >> op;
        if (op == "get") {
            int key;
            cin >> key;
            cout << obj->get(key) << "\n";
        }
        else if (op == "put") {
            int key, value;
            cin >> key >> value;
            obj->put(key, value);
        }
    }
}