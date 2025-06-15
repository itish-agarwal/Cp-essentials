/*
Inline functions

An inline function is a request to the compiler to replace the function calls
with the actual function code (body) wherever it is invoked.

Instead of calling the function (which involves jumping to a new instruction
location), the compiler inserts ("inlines") the code directly into the calling
location.
*/

#include "bits/stdc++.h"
using namespace std;

// Using inline keyword
inline int add(int a, int b) {
    return a + b;
}

// Defining the function inside a class
// All functions defined inside a class definition are implicitly inline.
class Math {
public:
    int cube(int x) {
        return x * x * x;
    }
};

/*
How inline functions work internally
When the compiler sees an inline function:
-> It tries to replace the function call with the actual code.
-> This avoids the overhead of function calls: no stack push/pop, no jump.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
}

/*
Why not make every function inline?

For following reasons:
1. Code Bloat
   
   -> Inserting function code everywhere its used increases binary size(called 
      code bloat). This leads to:
      * Poorer instruction cache usage
      * Slower performance in some cases

2. Maintanence and Debugging
    
   -> Stack traces during debugging can become harder to follow
   -> Inlined functions don't appear in traces since they were "injected"

3. Diminishing Returns

   -> Large functions, recursive calls, or rarely-used functions dont benefit
   -> Modern compilers already auto-inline where beneficial
*/