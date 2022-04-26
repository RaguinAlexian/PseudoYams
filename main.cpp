#include <iostream>
#include <string>
#include <vector>
#include "dice.cpp"
#include "combinaison.cpp"
#include "points.cpp"

int main()
{
    Dice * testDe = new Dice(6, 1);
    string retour;
    vector<int> dices;
    char ch = '0';
    char ch2 = '1';
    bool ok = false;
    int score = 0;
    string figure;

    cout << "Vos dés se lancent" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        testDe->throwDice();
        dices.push_back(testDe->getValue());
    }
    cout << "Le résultat de vos dés sont " << std::endl;
    for (auto i = dices.begin(); i != dices.end(); ++i)
    {
        cout << *i << std::endl;
    }

    int relance = 1;
    while (relance < 3)
    {
        cout << "Veuillez indiquez pour chaque dé si vous voulez relancer 0 pour non et 1 pour oui, votre message doit ressembler à '01100' : ";
        cin >> retour;
        if (retour.find(ch) != string::npos || retour.find(ch2) != string::npos)
        {
            ok = true;
        }
        while (retour.length() != 5 || ok == false)
        {
            cout << "Veuillez indiquez pour chaque dé si vous voulez relancer 0 pour non et 1 pour oui, votre message doit ressembler à '01100' : ";
            cin >> retour;
            for (auto i = retour.begin(); i != retour.end(); ++i)
            {
                if (*i != '0' || *i != '1')
                {
                    ok = false;
                    break;
                }
                else
                {
                    ok = true;
                }
            }
        }
        if (retour != "00000")
        {
            cout << "Vos dés vont être relancés." << std::endl;
            for (int i = 0; i < 5; i++)
            {
                if (retour[i] == '1')
                {
                    testDe->throwDice();
                    dices[i] = testDe->getValue();
                }
            }
            cout << "Voici vos nouveaux résultats de dés " << std::endl;
            for (auto i = dices.begin(); i != dices.end(); ++i)
            {
                cout << *i << std::endl;
            }
        }
        else{
            relance = 4;
        }
        relance = relance +1;
    }
    figure = combi(dices);
    cout << figure << std::endl;
    cout << "Vous obtenez : " << points(figure, dices) << " points " << std::endl;
}