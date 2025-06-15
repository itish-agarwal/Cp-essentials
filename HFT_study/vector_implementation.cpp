#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class MyVector {
private:
    T* data;          // pointer to the array
    size_t sz;        // current number of elements
    size_t cap;       // current capacity

    void resize_capacity(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; ++i)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    MyVector() : data(nullptr), sz(0), cap(0) {}

    ~MyVector() {
        delete[] data;
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

    void push_back(const T& value) {
        if (sz == cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            resize_capacity(new_cap);
        }
        data[sz++] = value;
    }

    void pop_back() {
        if (sz > 0) --sz;
    }

    T& operator[](size_t index) {
        if (index >= sz) throw out_of_range("Index out of bounds");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= sz) throw out_of_range("Index out of bounds");
        return data[index];
    }

    void print() const {
        for (size_t i = 0; i < sz; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    MyVector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2);

    vec.print();  // 0 2 4 6 8 10 12 14 16 18

    vec.pop_back();
    vec.print();  // 0 2 4 6 8 10 12 14 16

    cout << "vec[3] = " << vec[3] << endl;
    cout << "Size = " << vec.size() << ", Capacity = " << vec.capacity() << endl;
}
