#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    string job;
};

void print(Person* person) {
    cout << person->name << " is " << person->age << " years old and works as a " << person->job << endl;
}

int main() {
    Person person1;
    person1.name = "Harry";
    person1.age = 23;
    person1.job = "Programmer";
    
    cout << "Meet " << person1.name << endl;
    print(&person1);

    Person person2;
    person2.name = "Hermione";
    person2.age = 24;
    person2.job = "Manager";
    
    cout << "Meet " << person2.name << endl;
    print(&person2);

    return 0;
}