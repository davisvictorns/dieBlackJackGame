#ifndef _DIE_H_
#define _DIE_H_
#include <random>
using namespace std;

class Die{
  private:
    int value;
    random_device rd;
    std::mt19937 gen;
    uniform_int_distribution<int> dis;
  public:
    Die();
    int roll();
    int getValue();

};

#endif