#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dice{
protected:
    int _nbFace;
    int _value;

public:
    // Constructeurs
    Dice();
    Dice(int nbFace, int value);

    void throwDice();
    int getValue();
};

#endif