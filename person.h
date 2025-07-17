#include <iostream>
#include <string>
#include <string_view>

class Person {
  public:
    Person();
    Person(std::string_view name, int age);
    ~Person();
    std::string_view getname();
    int *getage();

    friend std::ostream &operator<<(std::ostream &out, Person &p);

    Person(Player p);

  private:
    std::string name;
    int *age;
};