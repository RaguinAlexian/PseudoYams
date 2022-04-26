#ifndef DICE_CPP
#define DICE_CPP
#include <stdlib.h>
#include <string>
#include <time.h>
#include "dice.h"

Dice::Dice() : _nbFace(6), _value(1) {}
Dice::Dice(int face, int number) : _nbFace(face), _value(number) {
    srand(time(NULL));
}

void Dice::throwDice()
{
    for (int i = 0; i < 5; i++)
    {
        _value = rand() % _nbFace + 1;
    }
}

int Dice::getValue()
{
    return _value;
}

#endif
