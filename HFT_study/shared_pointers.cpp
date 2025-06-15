/*

A shared_ptr<T> is a smart pointer provided by C++ that manages the
lifetime of a dynamically allocated object through reference counting.

When the last shared_ptr pointing to the object is destroyed,
the object is automatically deleted.

Reference Counting:
A shared pointer maintains a reference count, which tracks how many shared 
pointers are currently pointing to the same object.

When Are They Used? * * * 
Use shared_ptr when:

-> Multiple owners need to share responsibility for an object
-> You want automatic memory cleanup when the last owner goes out of scope
-> You want to avoid manual new/delete

Ideal for:
-> Graphs
-> Observer Patterns
-> Resource pools
-> Plugin systems

🚫 Avoid when:
-> You have single ownership → use unique_ptr instead
-> There's risk of circular references → use weak_ptr to break them

Shared pointers are suitable for scenarios where multiple parts of a program
need to access the same object and where ownership is shared.
*/

#include "bits/stdc++.h"
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "MyClass constructed\n";
    }

    ~MyClass() {
        cout << "MyClass destructed\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // p1 points to an integer with value 10
    // Internally, a reference count is maintained.
    shared_ptr<int> p1 = make_shared<int> (10);

    shared_ptr<MyClass> ptr1 = make_shared<MyClass>();

    {
        shared_ptr<MyClass> ptr2 = ptr1; // ptr2 shares ownership with ptr1, ref count is 2
        cout << "Inside scope\n";
    } // ptr2 goes out of scope, ref count becomes 1

    cout << "Outside scope\n";
    return 0; //ptr1 goes out of scope, ref count becomes 0 and the object is deleted
}