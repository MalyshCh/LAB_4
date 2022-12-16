#include "Weapon.h"
#include <string>

Weapon::Weapon(string name, float damage, float weight) {
    this->name = name;
    this->damage = damage;
    this->weight = weight;
};

Weapon::Weapon() : Weapon("���", 1, .1) {};

Weapon::~Weapon() {
    outputData();
    cout << " // ������" << endl;
};

void Weapon::outputData() {
    cout << "Weapon :" <<
        " �������� - " << name <<
        ", ��������� ���� - " << damage <<
        ", ��� - " << weight;
};

bool Weapon::isImposibleLift(float maxWeight) {
    if (maxWeight < weight) return true;
    return false;
};

float Weapon::sumWeights(float addWeight) {
    return (weight + addWeight);
};

float Weapon::sumWeights(Weapon* transferablWeapon) {
    return sumWeights((*transferablWeapon).weight);
};
