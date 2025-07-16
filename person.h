#include <iostream>
#include <string>
#include <string_view>

class Person {
  public:
    Person();
    Person(std::string_view name, int age);
    ~Person();

    friend std::ostream &operator<<(std::ostream &out, Person p);

  protected:
    std::string name;
    int *age;
}