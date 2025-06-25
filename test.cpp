#include <iostream> // std::string works without including this because g++'s
#include <string>   // implementation for iostream automatically includes a part
                    // of the string library - not in the c++ standard - compiler specific

int main() {
    /*
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
    std::cin >> std::ws;          // whitespace delimited std::cin reads leave whitespaces
    std::getline(std::cin, line); // in the input stream. using std::ws to clean first

    std::cout << "Entered line: " << line << std::endl;

    int num1 = 15; // initializes to garbage value if you do int num;
    int num2 = 017;
    int num3 = 0xF;
    int num4 = 0b1111;

    std::cout << "Numbers are: " << num1 << " " << num2 << " " << num3 << " " << num4 << std::endl;

    int num5{};  // initializes to 0 by default - raises error or warning instead of implicit type
                 // casting
    int num6(5); // functional variable initialization - implicitly typecasts from float to int

    std::cout << num5 << " " << num6 << std::endl;
    std::cout << "Space occupied by integers: " << sizeof(num5) << std::endl;
    */
    std::cout << "Space occupied by bool: " << sizeof(bool) << std::endl;
    std::cout << "Space occupied by short and long int: " << sizeof(short int) << " "
              << sizeof(long int) << std::endl;
}