#ifndef POINTS_CPP
#define POINTS_CPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int points(string figure, vector<int> dices){
    int result = 0;
    if (figure == "Yams")
        {
            return 50;
        }
        else if (figure == "Grande suite")
        {
            return 40;
        }
        else if (figure == "Petite suite")
        {
            return 30;
        }
        else if (figure == "Full")
        {
            return 25;
        }
        else if (figure == "Carre")
        {
            for(int i = 0; i < 5 ; i++){
                result = result + dices[i];
            }
            return result;
        }
        else if (figure == "Brelan")
        {
            for(int i = 0; i < 5 ; i++){
                result = result + dices[i];
            }
            return result;
        }
        else
        {
            return 0;
        }
}

#endif
