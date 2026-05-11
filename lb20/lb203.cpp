#include <iostream>

using namespace std;

class AdHocSquare {
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
};

AdHocSquare::AdHocSquare(double side) {
    if (side >= 0) {
        this->side = side;
    } else {
        this->side = 0;
    }
}

void AdHocSquare::set_side(double side) {
    if (side >= 0) {
        this->side = side;
    }
}

double AdHocSquare::get_area() {
    return this->side * this->side;
}


class LazySquare {
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double side) {
    if (side >= 0) {
        this->side = side;
    } else {
        this->side = 0;
    }
    this->side_changed = true;
}

void LazySquare::set_side(double side) {
    if (side >= 0 && this->side != side) {
        this->side = side;
        this->side_changed = true;
    }
}

double LazySquare::get_area() {
    if (this->side_changed) {
        this->area = this->side * this->side;
        this->side_changed = false;
    }
    return this->area;
}

int main() {
    AdHocSquare adhoc(4.0);
    cout << "AdHoc area: " << adhoc.get_area() << endl;
    adhoc.set_side(5.0);
    cout << "AdHoc area after change: " << adhoc.get_area() << endl;

    LazySquare lazy(4.0);
    cout << "Lazy area: " << lazy.get_area() << endl;
    lazy.set_side(6.0);
    cout << "Lazy area after change: " << lazy.get_area() << endl;

    return 0;
}