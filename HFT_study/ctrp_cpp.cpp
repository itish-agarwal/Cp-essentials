/*
Crtp (Curiously Recurring Template Pattern)

Compile time polymorphism (Zero overhead at runtime)

It is a C++ idiom where a class Derived inherits from a template base class,
and passes itself (Derived) as a template argument to the base class.
*/

#include "bits/stdc++.h"
using namespace std;

template<typename T>
class Base {
public:
    void interface() {
        // call implementation provided by the derived class
        static_cast<T*>(this) -> implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        cout << "Derived implementation\n";
    }
};

/*
Whats happening?
-> Base<Derived> is the base class - but its templated on Derived
-> This allows Base to call functions implemeneted in Derived, even though
it doesn't know about Derived directly.
-> static_cast<Derived*>(this) is key - it's a compile-time cast to call 
derived class functions.
*/

/* Why use CRTP?

-> Avoid virtual functions (zero runtime cost).
-> Achieve static polymorphism.
-> Reuse code across multiple derived classes.
-> Implement things like mixins, policy-based design, and compile-time
polymorphic behaviour.
*/

/*
How It Works Internally
-> All logic is resolved at compile time.
-> No vtable or dynamic dispatch.
-> No runtime overhead - everything is inlined and optimized by compiler.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
}