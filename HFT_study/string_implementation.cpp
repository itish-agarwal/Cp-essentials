#include <iostream>
#include <cstring>  // for strlen, strcpy
using namespace std;

class MyString {
private:
    char* data;
    size_t sz;
    size_t cap;

    void ensure_capacity(size_t min_capacity) {
        if (min_capacity > cap) {
            size_t new_cap = max(min_capacity, cap * 2);
            char* new_data = new char[new_cap + 1]; // +1 for null-terminator
            if (data)
                strcpy(new_data, data);
            delete[] data;
            data = new_data;
            cap = new_cap;
        }
    }

public:
    MyString() : data(new char[1]), sz(0), cap(0) {
        data[0] = '\0';
    }

    MyString(const char* str) {
        sz = strlen(str);
        cap = sz;
        data = new char[cap + 1];
        strcpy(data, str);
    }

    ~MyString() {
        delete[] data;
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

    const char* c_str() const { return data; }

    void push_back(char c) {
        ensure_capacity(sz + 1);
        data[sz++] = c;
        data[sz] = '\0'; // maintain null-termination
    }

    void append(const char* str) {
        size_t len = strlen(str);
        ensure_capacity(sz + len);
        strcpy(data + sz, str);
        sz += len;
    }

    char& operator[](size_t index) {
        return data[index]; // assume index < sz for simplicity
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    void print() const {
        cout << data << endl;
    }
};

int main() {
    MyString s("Hello");
    s.push_back(' ');
    s.append("World!");

    s.print();  // Hello World!
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;
    cout << "Char at 1: " << s[1] << endl;

    return 0;
}