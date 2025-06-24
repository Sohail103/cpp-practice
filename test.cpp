#include <iostream>

int main()
{
    std::cout << "Number1" << std::endl;
    std::cout << "Number2\n";
    std::cout << "Number3" << std::endl;
    std::cerr << "Errors" << std::endl;
    std::cout << "Line after error" << std::endl;

    std::string name;
    int age;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Entered name: " << name << std::endl;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Age: " << age << std::endl;

    std::cout << "Enter name and age in one line: ";
    std::cin >> name >> age;
    std::cout << "Name: " << name << ", Age: " << age << std::endl;

    std::cout << "Enter a line of text: ";
    std::string line;
    std::getline(std::cin, line);
    std::cout << "Entered line: " << line << std::endl;
}