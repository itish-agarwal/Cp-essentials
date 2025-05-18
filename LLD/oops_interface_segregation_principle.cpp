// Interface Segregation Principle
// Clients should not be forced to depend on methods that they do not use.

#include "bits/stdc++.h"
using namespace std;

// class ShapeInterface {
// public:
//     virtual double GetArea() = 0; // pure virtual function

//     virtual double GetVolume() = 0;
// };

class TwoDimensionalShapeInterface {
public:
    virtual double GetArea() = 0;
};

class ThreeDimensionalShapeInterface {
public:
    virtual double GetArea() = 0;

    virtual double GetVolume() = 0;
};

class Sphere: public ThreeDimensionalShapeInterface {
public:
    Sphere(int r): radius_(r) {}

    double GetArea() override {
        return 4 * 3.14 * radius_ * radius_;
    }

    double GetVolume() override {
        return (4 * 3.14 * radius_ * radius_ * radius_) / 3;
    }

private:
    int radius_;
};

// Now we want to implement Square
class Square: public TwoDimensionalShapeInterface {
public:
    Square(int len): len_(len) {}

    double GetArea() override {
        return len_ * len_;
    }

    // But there is not concept of volume of a square

private:
    int len_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Sphere sphere(2);
    cout << sphere.GetArea() << endl;

    // Now lets suppose i want to implement Square

    Square square(5); // code will not compile, since Square does not implement GetVolume.

    // Thats what the principle says -> client should not be forced to implement what it does 
    // not need. Here, Square is forced to implement GetVolume, which it does not need.

    // How to fix? Use Interface segregation -> Break ShapeInterface into 2 new interfaces:
    // TwoDimensionalShapeInterface and ThreeDimensionalShapeInterface 
    // and remove GetVolume from TwoDimensionalShapeInterface.

    // Basically segregate interfaces as per your needs, but dont force client classes
    // to implement functions if they do not require it.
}