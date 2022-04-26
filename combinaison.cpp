#ifndef COMBINAISON_CPP
#define COMBINAISON_CPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string combi(vector<int> setDices)
{

    vector<int> sortedDice = {};
    for (int i = 0; i < 5; i++)
    {
        sortedDice.push_back(setDices[i]);
    }
    sort(sortedDice.begin(), sortedDice.end());

    int yams = 0;
    int carre = 0;
    int compt = 0;
    int brelan = 0;
    bool car = false;
    bool yam = false;
    bool ptSuite = false;
    bool grSuite = false;
    bool ful = false;

    for(int i = 0; i < 4; i++){
        if(sortedDice[i] < sortedDice[i+1] && sortedDice[i] + 1 == sortedDice[i+1]){
            compt = compt + 1;
        }
    }
    if(compt == 4){
        grSuite = true;
    }
    else if(compt == 3){
        ptSuite = true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (sortedDice[i] == sortedDice[i+1])
        {
            yams = yams + 1;
        }
    }
    if (yams == 4)
    {
        return "Yams";
    }

    if (grSuite == true)
    {
        return "Grande suite";
    }

    if (ptSuite == true)
    {
        return "Petite suite";
    }


    if (sortedDice[0] == sortedDice[1] && sortedDice[0] == sortedDice[2] && sortedDice[3] == sortedDice[4] && sortedDice[0] != sortedDice[3])
    {
        ful = true;
        return "Full";
    }

    if (sortedDice[3] == sortedDice[4] && sortedDice[2] == sortedDice[3] && sortedDice[0] == sortedDice[1] && sortedDice[0] != sortedDice[4])
    {
        ful = true;
        return "Full";
    }

    for (int i = 0; i < 4; i++)
    {
        if (sortedDice[i] == sortedDice[i + 1])
        {
            carre = carre + 1;
        }
    }
    if (carre == 3)
    {
        car = true;
        return "Carre";
    }

    for (int i = 0; i < 4; i++)
    {
        if (sortedDice[i] == sortedDice[i + 1] && sortedDice[2] == sortedDice[i])
        {
            brelan = brelan + 1;
        }
    }
    if (brelan == 2 && car == false && ful == false)
    {
        return "Brelan";
    }
    return "Echec";
}

#endif
