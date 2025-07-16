#ifndef PERSON_H
#include "person.h"
#endif

#ifndef PERSON_H
#define PERSON_H
class Player : public Person {
  public:
    Player();
    Player(int gamenum);
    ~Player();

    int getgamenum();

    friend std::ostream &operator<<(std::ostream &out, Player &p);

  private:
    int gamenum;
};

#endif