// Liskov Substitution Principle
// If S is a subtype of T, then objects of type T in a program may be replaced with
// with objects of type S without altering any of the desirable properties of the 
// program.

#include "bits/stdc++.h"
using namespace std;

class Rectangle {
public:
    Rectangle(int l, int w): length_(l), width_(w) {}

    int GetPerimeter() {
        return 2 * (length_ + width_);
    }

    int GetArea() {
        return length_ * width_;
    }

    void PrintInfo() {
        cout << "Hello from Rectangle" << '\n';
    }
    
private:
    int length_, width_;
};

class Square: public Rectangle {
public:
    Square(int len): Rectangle(len, len) {}

    void PrintInfo() {
        cout << "Hello from Square" << '\n';
    }
};

pair<int, int> GetRectangleInfo(Rectangle &rect) {
    return {rect.GetArea(), rect.GetPerimeter()};
}

void PrintInfo(Rectangle &rect) {
    rect.PrintInfo();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Rectangle rect(4, 2);

    auto it = GetRectangleInfo(rect);
    cout << it.first << " " << it.second << '\n';

    // Rectangle is class T in above principle

    // Now, if we have a subclass of Rectangle: class Square
    // If I substitute Square class (in place of Rectangle) in GetRectangleInfo, 
    // the code should not break

    Square square(5);
    it = GetRectangleInfo(square);
    cout << it.first << " " << it.second << '\n';

    // If somehow while calling GetRectangleInfo on square, the code was breaking... then we 
    // are violating Liskov Substitution Principle.

    PrintInfo(rect);
    PrintInfo(square); // Both print 'Hello from Rectangle' since there is no override    
}