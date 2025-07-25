#include <iostream> // std::string works without including this because g++'s
#include <string>   // implementation for iostream automatically includes a part
                    // of the string library - not in the c++ standard - compiler specific

#include <cctype> // for strings and string manipulation
#include <cmath>
#include <cstring> // for copying and concatenating strings
#include <iomanip> // lets you set the precision of floating point numbers
#include <limits> // lets you check the min, max or lowest value of a datatype (float, int, short, etc)

// to make a function change multiple outputs, pass values by reference and change within function
void max_str(const std::string &input1, const std::string input2, std::string &output) {
    if (input1 > input2)
        output = input1;
    else
        output = input2;
}

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

    std::cout << "Space occupied by bool: " << sizeof(bool) << std::endl;
    std::cout << "Space occupied by short and long int: " << sizeof(unsigned short int) << " "
              << sizeof(long int) << std::endl;
    std::cout << "Space occupied by long long: " << sizeof(long long int) << std::endl;

    // On 64 bit linux systems, long long is the same size (8 bytes) as long
    // but on windows long is 4 bytes and long long is 8 bytes
    // for cross platform code, long long is the safest bet as that is guaranteed to be 8 bytes
    // size of long has to be atleast 4 bytes but in 64 bit linux it is 8 bytes
    // suffix long double numbers during initialization with L
    // suffix float numbers with f during initialization
    // if correct suffix isnt used - type mismatch - lost data

    std::cout << "Size of double and long double: " << sizeof(double) << " " << sizeof(long double)
              << std::endl;
    std::cout << (1.0 / 0.0f - 1.0 / 0.0f)
              << std::endl; // can divide float by 0 to get inf
                            // compiler wont raise warning if divided by 0.0f
                            // will raise warning if divided by 0
                            // will raise error if first number is an integer (1)
                            // subtracting inf - inf gives nan

    float number1{1.082328293f}; // precision for float: 7, double: 15
    std::setprecision(20);       // control precision from std::cout
    std::cout << "Floating point number: " << number1 << std::endl;


    bool boo1{true};
    std::cout << boo1 << std::endl; // displays output in cout as 1/0 by default
    std::cout << std::boolalpha;    // forces output to format booleans as true/false
    std::cout << boo1 << std::endl;

    char ch1{'a'};
    int ch1num{static_cast<int>(ch1)};
    std::cout << ch1 << ": " << ch1num << std::endl;

    auto var{13.0};
    double vard{13.0};
    std::cout << "Auto typed variable: " << var << "\n";
    std::cout << "Double typed variable: " << vard << "\n";
    std::cout << "Sizes of auto typed double and double: " << sizeof(var) << " " << sizeof(vard)
              << "\n";


    std::cout << std::setw(15) << "Last name" << std::setw(10) << "First name" << std::setw(5)
              << "Age" << std::endl;
    std::cout << std::setw(15) << "Daniel" << std::setw(10) << "Gray" << std::setw(5)
              << "25" // formatting cout output
              << std::endl;
    std::cout << std::setw(15) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33"
              << std::endl;
    std::cout << std::setw(15) << "Jordan" << std::setw(10) << "Parker" << std::setw(5) << "45"
              << std::endl;
    std::cout << std::setw(15) << "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21"
              << std::endl;
    std::cout << std::setw(15) << "Josh" << std::setw(10) << "Carr" << std::setw(5) << "27"
              << std::endl;
    std::cout << std::setw(15) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29"
              << std::endl;


    std::cout << std::scientific << 14.23
              << std::endl; // to print floating point values in scientific notation
    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // to reset to default

    std::cout << "The range for short is from " << std::numeric_limits<short>::min() << " to "
              << std::numeric_limits<short>::max() << std::endl;
    std::cout << "The range for int is from " << std::numeric_limits<int>::min() << " to "
              << std::numeric_limits<int>::max() << std::endl;
    std::cout << "The range for long is from " << std::numeric_limits<long>::min() << " to "
              << std::numeric_limits<long>::max() << std::endl;
    std::cout << "min - max for double is from " << std::numeric_limits<double>::min() << "to "
              << std::numeric_limits<double>::max() << std::endl;
    std::cout << "lowest - max for double is from " << std::numeric_limits<double>::lowest()
              << "to " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "log base e (54.59): " << std::log(54.59) << std::endl;
    std::cout << "log base 10 (10000): " << std::log10(10000) << std::endl;

    // You cannot do arithmetic operations on integers that are less than 4 bytes long (char and
    // short int) - compiler converts short int to int if doing arithmetic operations

    short int si1{12};
    short int si2{10};
    auto sum12 = si1 + si2;
    std::cout << "Size of si1 and si2: " << sizeof(si1) << " " << sizeof(si2) << " "
              << "\nSize of sum: " << sizeof(sum12)
              << std::endl; // compiler set sum12 to int and typecasted si1 and si2 into ints before
                            // adding


    int scores[] {10, 12, 15, 11, 18, 17, 22, 23, 24};

    std::cout << "scores size: " << std::size(scores) << std::endl;
    for(size_t i {0}; i<std::size(scores); i++)                      // preserves index info
        std::cout << "scores[" << i << "] = " << scores[i] << std::endl;


    for(auto val: scores)           // takes one element from the array at a time
        std::cout << val << std::endl;  // does not preserve information about indexes
*/
    /*
        const char *message{"Hello"};
        std::cout << *message << std::endl;

        int *p_num1{new int(22)};                // allocating memory dynamically to a pointer
        int *p_num2{new (std::nothrow) int{23}}; // doesnt throw exception when new operator fails
                                                 // simply returns nullptr if new failed

        std::cout << "p_num1: " << *p_num1 << std::endl;
        std::cout << "p_num2L " << *p_num2 << std::endl;

        delete p_num1;
        delete p_num2;
        p_num1 = nullptr; // avoid calling delete twice on a pointer - undefined behavior
        p_num2 = nullptr; // also avoid having 2 pointers pointing to the same location and then
                          // deleting one of them so the other also becomes invalid -
                          // instead keep one master pointer and all other are slaves if necessary
        try {
            // code
        } catch (const std::exception &e) // try catch block
        {
            std::cerr << e.what() << '\n';
        }
        {
            // int *p_number1{new int{15}}; // leads to memory leak because variable p_number1 dies
       out
            //  after its local scope is exited - memory leaks in nested scopes
        } // local variable p_number is gone after its scope is exited

        int *p_scores0{
            new (std::nothrow) int[5]{}}; // all values initialized to 0 - dynamically allocated
       arays int *p_scores1{new (std::nothrow) int[5]{1, 2, 3, 4, 5}}; // values initialized

        std::cout << *p_scores0 << std::endl;
        std::cout << *p_scores1 << std::endl;

        delete[] p_scores0;
        p_scores0 = nullptr;
        delete[] p_scores1;
        p_scores1 = nullptr;

        */
    /*
    // Dynamic vs static arrays
    int scores_stack[10]{1, 2, 3, 4, 5}; // static array - size is const
    // std::cout << std::size(scores_stack) << std::endl; // displays size of the static array

    int *scores_heap = new int[10]{1, 2, 3, 4, 5}; // dynamic array - size is not constant
    // std::cout << std::size(scores_heap) << std::endl;   // cannot print size of dynamic array

    for (auto val : scores_stack)
        std::cout << val << " "; // works with static arrays
    std::cout << "\n";

    for (auto val : scores_heap)  // doesnt work with dynamic arrays
        std::cout << val << " ";
    std::cout << "\n";
    */

    int int_value{45};
    double double_value{33.65};
    int &reference_to_int_value1{int_value};
    // int &reference_to_int_value2{int_value};
    // double &reference_to_double_value{double_value};

    std::cout << "int value: " << int_value
              << " and reference to int value: " << reference_to_int_value1 << std::endl;
    std::cout << "address of int value: " << &int_value
              << " and address of reference: " << &reference_to_int_value1 << std::endl;
    // references are somewhat like const pointers
    // they cannot be made to reference another variable - only the one they were initialized with

    return 0;
}