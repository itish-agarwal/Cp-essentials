/*
Static Variables
A static variable is one that retains its value between function calls
 and has internal linkage if declared at global scope.

Type                             Meaning
Static inside a function         Keeps its value across calls. Memory is allocated only once.
Static at global/class level     Scope is limited to the file/class; value persists.
Static in a class                Shared across all instances. Must be defined outside the class.
*/

#include "bits/stdc++.h"
using namespace std;

class MyClass {
public:
    static int value; // belongs to class, not objects.
    // all instances share it.
    // can be accessed with MyClass::value;
};

int MyClass::value = 42;

void fun() {
    static int a = 10;
}

void demo() {
    int a = 0;
    static int b = 0;
    a++;
    b++;
    cout << "a = " << a << ", b = " << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Static local variable
    static int count = 0;
    count++;

    cout << count << endl;    

    cout << MyClass::value << endl;

    demo();
    demo();
    demo();
}

/*
How Static Variables Work Internally

-> Storage: Stored in data segments (not stack/heap)
-> Initialization: Happens once, typically before first use (or at program load for globals).
-> Lifetime: Whole program duration
-> Scope: Depends: local (function), class (member), file (global static).

*/

/*
Why not make everything static?
1.Loss of flexibility:
-> Static variables can’t be passed, reused, or independently scoped easily.
-> Not thread-safe by default.
-> Might cause issues while unit testing the system.

2. Memory always allocated:
-> Even if unused later, it stays in memory.

Static variables (like global variables and static locals) are stored in either:

Data Segment → if initialized (e.g., static int x = 42;)

BSS Segment → if uninitialized (e.g., static int x;)
*/