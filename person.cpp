#include "person.h"

Person::Person() = default;

Person::Person(std::string_view name, int age) {
    this->name = name;
    this->age = new int{age};
}

Person::~Person() = default;

std::string_view Person::getname() { return this->name; }

int *Person::getage() { return this->age; }

std::ostream &operator<<(std::ostream &out, Person &p) {
    out << "Name: " << p.getname() << ", Age: " << p.getage() << "\n";
    return out;
}