#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Weapon {
public: // 1.
    string name;    // имя
    float damage;   // урон
    float weight;   // вес

    Weapon(string name, float damage, float weight) { // 2.
    this->name = name;
    this->damage = damage;
    this->weight = weight;
    };

    Weapon() : Weapon("Нож", 1, .1) {}; // 3.
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "4 Лабораторная работа. Вопрос 1." << endl;

    // 1. Создайте класс оружия со следующими полями: 
    // название оружия, наносимый урон и его вес.

    // 2. Создайте конструктор, принимающий 3 параметра и 
    // использующий их для инициализации переменных класса.

    // 3. Создайте конструктор без параметров, который будет 
    // вызывать конструктор из предыдущего пункта, передавая 
    // туда какие-то значения по умолчанию.

    // 4. Создайте 2 объекта, используя конструктор с 
    // параметрами и без.

    Weapon pistol = Weapon("Пистолет", 5, .790);
    Weapon knife;

    // 5. Выведите значения всех переменных обоих 
    // экземпляров в консоль.

    cout << "Pistol :" << 
        " название - " << pistol.name <<
        ", наносимый урон - " << pistol.damage <<
        ", вес - " << pistol.weight << endl;
    cout << "Knife :" <<
        " название - " << knife.name <<
        ", наносимый урон - " << knife.damage <<
        ", вес - " << knife.weight << endl;
}
