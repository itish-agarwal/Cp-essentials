//OBJECT RELATIONSHIP: Association (many to many)

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

class Person;

class Home {
public:
    Home(string address): address_(address) {}

    ~Home() {
        cout << "~Home: " << address_ << " called" << '\n';
    }

    void AddPerson(Person *person) {
        persons_.push_back(person);
    }

    string address_;

private:
    vector<Person*> persons_;
};

class Person {
public:
    Person(string person_name): heart_(person_name), person_name_(person_name) {}

    ~Person() {
        cout << "~Person " << person_name_ << " called" << '\n';
    }

    string GetAddress() {
        return home_ -> address_;
    }

    void AddHome(Home* home) {
        homes_.push_back(home);
    }

private:
    Heart heart_; // Composition

    Home* home_; // Aggregation

    vector<Home*> homes_; // Association

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
    
    Home home1("delhi");
    Home home2("bangalore");

    // Both live in same home
    Person *p1 = new Person("A");
    Person *p2 = new Person("B");

    p1 -> AddHome(&home1);
    p1 -> AddHome(&home2);

    delete p1;

    cout << p2 -> GetAddress() << '\n';

    delete p2;

    // home is same for both persons, but its lifetime is not 
    // managed by any particular person.
    // We dont want that home is destroyed when person is destroyed.

    // Use pointers to home object in person class
}

/*
To qualify as a association, an object and a part must have the 
following relationship:

-> The part (member) is otherwise unrelated to the object (class)
-> The part (member) can (if desired) belong to more than one object (class) at a time 
-> The part (member) does not have its existence managed by the object (class)
-> The part (member) MAY or MAY NOT know about the existence of the object (class)

// Eg:
Consider the relationship between a person and home address. 
A person can have multiple homes.

*/