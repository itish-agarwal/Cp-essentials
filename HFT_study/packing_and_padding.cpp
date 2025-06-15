/*
Packing and Padding

The size of a class is the sum of the sizes of its members, plus padding, 
plus base class overhead (if any), plus vtable pointer (if polymorphic).

size(class) = size(members) + padding + base class overhead (if any) + vtable ptr(if any)
*/

/* Padding:
Padding is extra bytes added by the compiler to align data members 
according to their alignment requirements. 

Why is alignment important?
-> CPU accesses aligned data faster.
-> Misaligned access can cause performance penalties or hardware traps.

*/

/* Packing: Forcing the layout
Packing disables or reduces padding by using compiler-specific pragmas or attributes.

#pragma pack(1)
.... class definition
#pragma pack()

Warning:
-> Packing saves memory but can decrease performance.
-> Use in networking, file formats, hardware registers.
*/

/*Empty Class Size:
Even an empty class has non-zero size. (=1 byte)
To ensure that every object has a unique address. 
If it were 0 bytes, multiple objects could share the same address.
*/

#include "bits/stdc++.h"
using namespace std;

// Expected size: 5 bytes, actual size: 8 bytes
// Why? Because the int is placed at offset 4, and 3 bytes are added after char
// <char> _ _ _ <int> <int> <int> <int>
struct A {
    char c; // 1 byte
    int i; // 4 bytes
};

// Packing
#pragma pack(1)
struct B {
    char c;
    int i;
};
#pragma pack()

// How to calculate class size?
struct C {
    char a; // 1 byte
    int b; // 4 bytes (starts at offset 4)
    char c; //  1 bytes (starts at offset 8)
};

/* Steps:
1. char a : offset 0
   Padding: 3 bytes 
2. int b : offset 4
3. char c : offset 8
   Padding: 3 bytes

Total size: 12 bytes

<char> _ _ _ <int> <int> <int> <int> <char> _ _ _ 
*/


/* Inheritance and Size:
Derived inherits int x {4 bytes}
Adds char y {1 byte}
Needs padding after y
Total size: 8 bytes
*/

class Base {
    int x;
};

class Derived : public Base {
    char y;
};

/* Virtual Functions and vtable
*/
class AA {
    virtual void foo() {}
};
// A vtable pointer is added (8 bytes)
// Even if class has no data, size = 8 bytes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << sizeof(A) << '\n'; // 8
    cout << sizeof(B) << '\n'; // 5
}


/* Tricky Questions:
Q) Whats the size of:
class A {};
class B : public A{};

sizeof(A) = 1;
sizeof(B) = 1;

Q) Class with only static members?
class A {
    static int x;
};

sizeof(A) = 1 (empty class rule);

Q) What if class has only functions?
class A {
    void foo();
};

Functions dont take space in object.
sizeof(A) = 1;
*/