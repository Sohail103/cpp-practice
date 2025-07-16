#include "player.h"

int main() {
    Person p1("abcd", 19);
    Player player("efgh", 50, 25);
    std::cout << p1 << std::endl;
    std::cout << player << std::endl;
    return 0;
}