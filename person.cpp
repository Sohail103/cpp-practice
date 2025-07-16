#include "person.h"

Person::Person() = default;

Person::Person(std::string_view name, int age) {
    this->name = name;
    this->age = new int{age};
}

Person::~Person() = default;

std::ostream &operator<<(std::ostream &out, Person p) {}