/*
Const Variables
A const variable is read-only: once it’s initialized, it cannot be changed.
Think of it like a lock on data – you can read it, but not modify it.
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int x = 10;
    // x = 20;  Error

    int a = 10, b = 20;

    // pointer to const value
    const int* p = &a; // pointer to const value
    // *p = 15; // cannot modify value
    p = &b; // can change address

    // const pointer to value
    int* const q = &a; // const pointer to value
    *q = 30; // can modify value
    // q = &b; // cannot change address

    // const pointer to const value
    const int* const r = &a;
    // *r = 40;        // ❌
    // r = &b;         // ❌
}

/*

Rule of thumb:
const int* -> data is constant (POINTER TO CONST)
int* const -> pointer is constant (CONST POINTER)
const int* const -> both constant
*/

/*
-> Pointers to constants

Data pointed by the pointer is constant and cannot be changed. 
Although, pointer itself can change and point somewhere else.

int h{100}, l{66};

const int* score {&h}; (const int)* score {&h}

*score=78 // ERROR
*/

/*
-> Constant pointers

The pointer refers to a fixed memory location, and this cannot change.
Although, the value at that location can change.

int a{90}, b{50};

int* const ptr{&a};

ptr = &b; // ERROR
*/

/*
-> Constant Pointer to Constants
In the constant pointers to constants, the data pointed to by the
pointer is constant and cannot be changed. The pointer itself is constant and cannot change and point somewhere else

int a{90}, b{50};

const int* const ptr{&a};

*ptr = 60; // ERROR
ptr = &b; // ERROR
*/