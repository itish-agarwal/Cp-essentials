/*
Smart Pointers

Problem with normal pointers:
-> Memory Leaks: This occurs when memory is repeatedly allocated by a program but
never freed. This leads to excessive memory consumption and eventually leads to a system crash.
-> Wild Pointers: A pointer that never be initialize with valid object or address called wild pointer.
-> Dangling Pointers: Assume there is a pointer that refers to memory which was deallocated earlier 
in the program, that pointer is called a dangling pointer.
*/

/*
Smart Pointers:
Smart Pointer is a wrapper class over a pointer that acts as a 
pointer but automatically manages the memory it points to.

It ensures that memory is properly deallocated when no longer needed,
preventing memory leaks. 

C++ libraries provide implementations of smart pointers in following
types:
-> auto_ptr
-> unique_ptr
-> shared_ptr
-> weak_ptr

*/

#include "bits/stdc++.h"
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /* 1. auto_pre
    In C++, auto_ptr is a smart pointer that automatically manages the lifetime of a dynamically
     allocated object. It takes ownership of the object it points to, ensuring
      that the object is automatically deleted when the auto_ptr goes out of
       scope.
    */
    
    // Deprecated since C++ 11, removed in C++ 17
    auto_ptr<int> ptr1(new int(10));
    cout << *ptr1 << '\n';

    /* 2. unique_ptr
    unique_ptr stores one pointer only at a time. We cannot copy unique_ptr, only 
    transfer ownership of the object to another unique_ptr using the move() method.
    */

    unique_ptr<Rectangle> p1(new Rectangle(10, 5));
    cout << p1 -> area() << '\n';

    unique_ptr<Rectangle> p2;

    //Copy the address of p1 into p2, delete p1
    p2 = move(p1);
    cout << p2 -> area() << '\n';

    /* 3. shared_ptr
    By using shared_ptr, more than one pointer can point to same object at a time, 
    and it will maintain a reference counter using the use_count() method.
    */

    shared_ptr<Rectangle> ps1(new Rectangle(10, 5));
    cout << ps1 -> area() << '\n';

    shared_ptr<Rectangle> ps2;

    // ps1 and ps2 are pointing to same object
    ps2 = ps1;

    cout << ps2 -> area() << '\n';
    cout << ps1.use_count() << '\n';

    /* 4. weak_ptr
    weak_ptr is a smart pointer that holds a non-owning reference to an object. 
    It's much more similar to shared_ptr except it will not maintain a reference 
    counter. In this case, a pointer will not have a stronghold on the object. 
    The reason is to avoid the circular dependency created by two or more object
     pointing to each other using shared_ptr.
    */

    shared_ptr<Rectangle> ps10 (new Rectangle(10, 5));
    weak_ptr<Rectangle> pw2(ps10);

    // Returns the number of shared_ptr objects that manage the object
    cout << ps10.use_count() << '\n';
}