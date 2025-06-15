/*
In C++, a virtual destructor is a destructor declared with the virtual
 keyword within a base class. It ensures that when a derived class 
 object is deleted through a pointer to the base class, the correct 
 destructor for the derived class is called.

 When you have a hierarchy of classes and you delete an object through a 
 base class pointer, the virtual destructor ensures that the correct destructor
  is called. Without it, only the base class destructor would be called, 
  leading to memory leaks and undefined behavior if the derived class has 
  resources to free.
*/

#include "bits/stdc++.h"
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor is called\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived destructor is called\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Base *ptr = new Derived();
    delete ptr;
    return 0;
}

/*
RULES:
1. If a class has any virtual functions, it should have a virtual destructor.

2. A virtual destructor does not override the destructor of the 
derived class. Instead, the derived class destructor is called first, 
followed by the base class destructor.

3. A pure virtual destructor is allowed, but it must have a function body.

4. Constructors cannot be virtual.
*/