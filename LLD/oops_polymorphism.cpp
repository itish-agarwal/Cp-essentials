#include "bits/stdc++.h"
using namespace std;

class Animal {
public:
    void Sound() {
        cout << "No Sound" << '\n';
    }
};

class Cat : public Animal {
public:
    void Sound() {
        cout << "Meow" << '\n';
    }
};

class Dog : public Animal {
    void Sound() {
        cout << "Bark" << '\n';
    }
};


// class DogChild : public Dog {
//     void Sound() {
//         cout << "Bark 2" << '\n';
//     }
// };

void PlaySound(Animal &a) {
    a.Sound();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Cat cat;
    cat.Sound();
    Animal &a = cat;

    PlaySound(a);
    // Dog dog;
    // cat.Sound();
    // PlaySound(animal);
    // PlaySound(cat);
    // PlaySound(dog);
}