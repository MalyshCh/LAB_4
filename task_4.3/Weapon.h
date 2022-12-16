#pragma once
#include <iostream>
//#include <string>

using namespace std;

class Weapon {
public:
    string name;
    float damage;
    float weight;

    Weapon(string name, float damage, float weight);

    Weapon();

    ~Weapon();

    void outputData();

    bool isImposibleLift(float maxWeight);

    float sumWeights(float addWeight);

    float sumWeights(Weapon* transferablWeapon);
};
