#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Weapon {
public: // 1.1.
    string name;    // имя
    float damage;   // урон
    float weight;   // вес

    Weapon(string name, float damage, float weight) { // 1.2.
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    };

    Weapon() : Weapon("Нож", 1, .1) {}; // 1.3.

    ~Weapon() { // 2.1.
        /*
        cout << "Weapon :" <<
            " название - " << name <<
            ", наносимый урон - " << damage <<
            ", вес - " << weight << 
            " // удален" << endl;
            */
        outputData();
        cout << " // удален" << endl;
    };

    void outputData() {
        cout << "Weapon :" <<
            " название - " << name <<
            ", наносимый урон - " << damage <<
            ", вес - " << weight;
    };

    bool isImposibleLift(float maxWeight) { // 2.5
        if (maxWeight < weight) return true;
        return false;
    };

    /*
    float sumWeights(Weapon* transferablWeapon) { // 2.6
        return (weight + (*transferablWeapon).weight);
    };
    */

    float sumWeights(float addWeight) { // 2.7
        return (weight + addWeight);
    };

    float sumWeights(Weapon* transferablWeapon) { // 2.8
        return sumWeights((*transferablWeapon).weight);
    };
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "4 Лабораторная работа. Вопрос 2." << endl;

    // 1. Создайте деструктор для класса оружия, в котором 
    // выведите в консоль все данные оружия и сообщение о том, 
    // что он удаляется.

    // 2. Создайте объект оружия и выведите его переменные в консоль.

    Weapon knife;
    knife.outputData();
    cout << endl;

    // 3. Создайте динамический объект оружия и выведите его 
    // переменные в консоль.

    Weapon* bow = new Weapon("Лук", 2, 4);
    (*bow).outputData();
    cout << endl;
    //delete bow; // !!! строка закомментирована для дальнейших вычислений

    // 4. Запустив программу и убедитесь, что в обоих случаях 
    // вызывается деструктор (разумеется, про delete для 
    // динамических объектов не нужно забывать).

    // 5. Добавьте метод в класс оружия, принимающий в качестве 
    // параметра максимально допустимый вес для оружия, и который 
    // возвращает true или false. Если максимально допустимый вес 
    // меньше, чем вес оружия, то возвращается true, а иначе false.
    // Своего рода, это проверка сможет ли поднять некто данное 
    // оружие или нет.

    cout << "2.5. Могу ли поднять лук (макс вес 1,5) - " << boolalpha << (*bow).isImposibleLift(1.5) << endl;

    // 6. Добавьте метод, принимающий объект оружия, и возвращающий 
    // суммарный вес текущего объекта и переданного.

    // cout << "2.6. Сколько весят лук и передаваемый нож - " << (*bow).sumWeaponWeight(&knife) << endl;
    cout << "2.6. Сколько весят лук и передаваемый нож - " << (*bow).sumWeights(&knife) << endl;

    // 7. Сделайте перегрузку для предыдущего метода, добавив ещё 
    // одну функцию класса, но принимающую уже просто вес.
    // Разумеется, функционал должен быть такой же : возврат суммы 
    // веса текущего объекта и переданного веса.
    
    cout << "2.7.1. Сколько весят нож и передаваемый лук - " << knife.sumWeights((*bow).weight) << endl;
    cout << "2.7.2. Сколько весят лук и дополнительный вес (10) - " << (*bow).sumWeights(10) << endl;

    // 8. Перепишите функцию, принимающую объект оружия так, чтобы 
    // она использовала созданную перегрузку.

    cout << "2.8. Сколько весят нож и передаваемый лук - " << knife.sumWeights(bow) << endl;

    // 9. Проверьте работу всех созданных функций класса.

    cout << "main закончился" << endl;
    delete bow;
}
