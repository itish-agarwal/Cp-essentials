#include <bits/stdc++.h>
using namespace std;

class LRUCache
{   
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int maxsize = 0;

    void touch(int id) {
        auto it = cache.find(id);
        int key = it -> first;
        order.erase(it -> second.second);
        order.push_front(key);
        it -> second.second = order.begin();
    }

public:

    LRUCache(int capacity)
    {
        maxsize = capacity;
        cache.clear();
        order.clear();
    }

    int get(int key)
    {
        if(cache.find(key) == cache.end())
            return -1;
        touch(key);
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if(cache.find(key) == cache.end()) {
            if((int)cache.size() == maxsize) {
                int del = order.back();
                cache.erase(del);
                order.pop_back();
            }
            order.push_front(key);
        } else {
            touch(key);
        }
        cache[key] = make_pair(value, order.begin());
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cap;
    cin >> q >> cap;
    LRUCache *obj = new LRUCache(cap);
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "get")
        {
            int key;
            cin >> key;
            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;
            obj->put(key, val);
        }
    }

    return 0;
}