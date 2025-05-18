// Open-closed principle: A class should be open for extension, but
// closed for modification.

#include "bits/stdc++.h"
using namespace std;

class StringFunctions {
public:
    virtual string Edit(string str1, string str2) = 0;
};

class AppendFunction: public StringFunctions {
public:
    string Edit(string str1, string str2) override {
        return str1 + str2;
    }
};

class ReverseAppendFunction: public StringFunctions {
public:
    string Edit(string str1, string str2) override {
        return str2 + str1;
    }
};

class CustomAppendFunction: public StringFunctions {
public:
    string Edit(string str1, string str2) override {
        return str1 + str1 + str2;
    }
};

// class TextEditor {
// public:
//     string Format(string str1, string str2) {
//         return str1 + str2;
//     }
// };

class TextEditor {
public:
    string Format(string str1, string str2, StringFunctions& func) {
        return func.Edit(str1, str2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    TextEditor editor;
    string str1, str2;
    cin >> str1 >> str2;

    AppendFunction append_function;

    cout << editor.Format(str1, str2, append_function) << '\n';
    
    // Now, we want to format in reverse order. (or return str1+str1+str2)

    // But TextEditor is already in production, don't modify it -> 
    // dont try to edit current function to expand functionality

    // So how to resolve this? Use interface and polymorphism

    // Make StringFunctions class -> and make different append requirements
    // as different classes

    // Notice how we are extending the funcionality of TextEditor -> 
    // any change required in append logic would be done outside.
}