#include <iostream>

using namespace std;

class Tree {
public:
    virtual void draw() {
    }
    virtual ~Tree() {}
};

class Tree1 : public Tree {
public:
    void draw() override {
        cout << "Drawing 1:\n";
        cout << " /\\\n";
        cout << "//\\\\\n";
    }
};

class Tree2 : public Tree {
public:
    void draw() override {
        cout << "Drawing 2:\n";
        cout << " /\\\n";
        cout << "/**\\\n";
    }
};

class Tree3 : public Tree {
public:
    void draw() override {
        cout << "Drawing 3:\n";
        cout << " /\\\n";
        cout << "/++\\\n";
    }
};

int main() {
    Tree* trees[3];
    trees[0] = new Tree1();
    trees[1] = new Tree2();
    trees[2] = new Tree3();

    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
    }

    for (int i = 0; i < 3; ++i) {
        delete trees[i];
    }

    return 0;
}