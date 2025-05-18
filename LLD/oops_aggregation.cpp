//OBJECT RELATIONSHIP: Aggregation (1 to many)

#include "bits/stdc++.h"
using namespace std;

class Heart {
public:
    Heart(string person_name): person_name_(person_name) {}

    ~Heart() {
        cout << "~Heart " << person_name_ << " called" << '\n';
    }

    void Beats();

private:
    string person_name_;
};

class Home {
public:
    Home(string address): address_(address) {}

    ~Home() {
        cout << "~Home: " << address_ << " called" << '\n';
    }

    string address_;
};

class Person {
public:
    Person(string person_name, Home *home): heart_(person_name), home_(home), person_name_(person_name) {}

    ~Person() {
        cout << "~Person " << person_name_ << " called" << '\n';
    }

    string GetAddress() {
        return home_ -> address_;
    }

private:
    Heart heart_; // Composition

    Home* home_; // Aggregation

    string person_name_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // COMPOSITION
    // Person a("A");
    // Person b("B");    

    // B will be destructed first -> it was allocated last on stack memory.

    // AGGREGATION
    
    Home home("delhi");

    // Both live in same home
    Person *p1 = new Person("A", &home);
    Person *p2 = new Person("B", &home);

    delete p1;

    cout << p2 -> GetAddress() << '\n';

    delete p2;

    // home is same for both persons, but its lifetime is not 
    // managed by any particular person.
    // We dont want that home is destroyed when person is destroyed.

    // Use pointers to home object in person class
}

/*
To qualify as a aggregation, an object and a part must have the 
following relationship:

-> The part (member) is a part of the object (class)
-> The part (member) can (if desired) belong to more than one object (class) at a time 
-> The part (member) does not have its existence managed by the object (class)
-> The part (member) does not know about the existence of the object (class)

// Eg:
Consider the relationship between a person and home address. Every 
person has an address. However, that address can belong to multiple 
persons at a time.

*/