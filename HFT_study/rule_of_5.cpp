/*
https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f

The "Rule of  Five" is a guideline for efficient
 and bug-free programming in C++. The Rule of Five states that,

If any of the below functions is defined for a class, then 
it is better to define all of them.


It includes the following functions of a class:

Destructor
Copy Constructor
Copy Assignment Operator
Move Constructor
Move Assignment Operator

*/

#include "bits/stdc++.h"
using namespace std;

class Student {
private:
    int id;
    // char* name;
    int* ptr;

public:
    Student() {
        this->id = 0;
        // this->name = nullptr;
    }

    Student(int x, int id) {
        this->id = id;
        // this->name = new char[strlen(name) + 1];
        this->ptr = new int(10);
        // strcpy(this->name, name);
    }

    // copy constructor
    Student(const Student& other) {
        this->id = other.id;
        this->ptr = new int(*other.ptr);
    }

    // copy assignment
    Student& operator=(const Student& rhs) {
        // self assignment check
        if (this != &rhs) {
            this->id = rhs.id;
            if (this->ptr) {
                delete ptr;
            }

            this->ptr = new int(*rhs.ptr);
        }

        return *this;
    }

    // move constructor
    Student(Student&& other) {
        this->id = other.id;
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }

    // move assignment
    Student &operator=(Student&& rhs) {
        if (this != &rhs) {
            this->id = rhs.id;

            if (this->ptr) {
                delete ptr;
            }

            this->ptr = rhs.ptr;
            rhs.ptr = nullptr;
        }

        return *this;
    }

    ~Student() {
        // delete[] this->name;
    }

    void printIntAddress() {
        cout << ptr << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Student s1(4, 1);
    Student s2 = s1;

    /*
When s2 is being constructed, the default copy
constructor for Student will be executed (as there's 
no user-defined copy constructor). A default copy 
constrcutor is supplied by the C++ compiler whenever 
there's a missing user-defined copy constructor. 
(Note: The rules are a bit more involved, but let's 
oversimplify things a bit here). The default copy 
constructor will copy each attribute of the class 
"as-is" (this is refered to as SHALLOW copy). 
Which means, both s1.name and s2.name point to the 
same C-string.

What happens when main ends? s2's destructor will be called, 
which will free the memory allocated for name C-string. 
Then, s1's destructor gets called which will again try 
freeing the memory for the name C-string. But it's 
already freed! This results in undefined behaviour.

To avoid this, suitable copy operations need to be provided. 
So now we add copy constructor and copy assignment functions
to the Student class.

Both the copy constructor and the copy assignment operator 
perform a deep copy of the dynamically allocated resourse.


Notice the && in the parameters of the move operations. Also, the
parameters are not marked as const as opposed to const parameters
in copy operations.

The move operations are called when copy of a soon-to-be-destroyed
(dying) object is being made. As the object is soon going to be 
destroyed, instead of making a copy, we make use of the dying 
object's resources. In essence, we steal resources from the dying object.
*/

    Student s3 = s1; //copy constructor
    Student s4;
    s4 = s1; // copy assignment

    Student s5(5, 2);
    Student s6 = move(s5); //move constructor
    Student s7;
    s7 = move(s5); // move assignment

    s1.printIntAddress();
    s2.printIntAddress();
}

// Shallow copy -> means copying by reference, both object's members point to 
// same memory

// Deep copy -> means copying by creating new heap memory, object's members
// point to different memory locations

/*
Move vs copying:

-> Move avoid deep copying, enables ownership transfer. 
-> Copy duplicates resources.
*/