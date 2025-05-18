#include "bits/stdc++.h"
using namespace std;

class A {
public:
    A() {
        cout << "Constructor A is called" << '\n';
    }
    ~A() {
        cout << "Destructor A is called" << '\n';
    }
};

class B : public A {
public:
    B() {
        cout << "Constructor B is called" << '\n';
    }
    ~B() {
        cout << "Destructor B is called" << '\n';
    }
};

class C : public B {
public:
    C() {
        cout << "Constructor C is called" << '\n';
    }
    ~C() {
        cout << "Destructor C is called" << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // A a; // Behaves normally
    // B b;
    C c;

    // To make B, make A must be called since 
    // B might have dependency on A

    // Most base class's constructor will get called first

    // In order which constructued, exact reverse
    // order will be destructed in

    // Most base class initialized first
    // Most derived class destructed first
}

// Best way to initialize parameters of Base class (when creating)
// object of Derived class is to call the constructor of Base
// class from the constructor of Derived class.