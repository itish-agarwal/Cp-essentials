//OBJECT RELATIONSHIP: Composition (1 to 1)

#include "bits/stdc++.h"
using namespace std;

class Heart {
public:
    Heart(string person_name): person_name_(person_name) {}

    ~Heart() {
        cout << "Destructor " << person_name_ << " Heart called" << '\n';
    }

    void Beats();

private:
    string person_name_;
};

class Person {
public:
    Person(string person_name): heart_(person_name) {}

    ~Person() {
        cout << "Destructor Person called" << '\n';
    }

private:
    Heart heart_; // Composition
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Person a("A");
    Person b("B");    

    // B will be destructed first -> it was allocated last on stack memory.
}

/*
To qualify as a composition, an object and a part must have the 
following relationship:

-> The part (member) is a part of the object (class)
-> The part (member) can only belong to one object (class) at a time
-> The part (member) has its existence managed by the object (class)
-> The part (member) does not know about the existence of the object (class)

It is denoted by a "Part-Of" relationship.

When the object dies, so does the member

In above code, Person (class) HAS-A Heart (member)

*/