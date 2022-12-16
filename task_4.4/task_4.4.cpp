#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Weapon {
    friend class Characteristic; // 6.
private:
    string name; // 1.
    float damage;
    float weight;

public:

    string getName() { // 2.
        return name;
    }

    float getDamage() { // 2.
        return damage;
    }

    float getWeight() { // 2.
        return weight;
    }

    void setDamage(float newDamage) { // 3.
        damage = newDamage;
    }

    Weapon(string name, float damage, float weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    };

    Weapon() : Weapon("Нож", 1, .1) {};

    ~Weapon() {
        outputData();
        cout << " // удален" << endl;
    };

    void outputData() {
        cout << "Weapon :" <<
            " название - " << name <<
            ", наносимый урон - " << damage <<
            ", вес - " << weight;
    };

    bool isImposibleLift(float maxWeight) {
        if (maxWeight < weight) return true;
        return false;
    };

    float sumWeights(float addWeight) {
        return (weight + addWeight);
    };

    float sumWeights(Weapon* transferablWeapon) {
        return sumWeights((*transferablWeapon).weight);
    };
};

class Characteristic { // 5.
private:
    float strength; // сила

public:
    Characteristic(float strength) {
        this->strength = strength;
    };

    float getDamage(Weapon weapon) { // 7.
        return (weapon.getDamage() + strength);
    }
};

class MyMath { // 9.
public:
    static int counter; // 10.

    static void Add() { // (сложение)
        counter++; // 11.
    };
    static void Sub() { // (вычитание)
        counter++; // 11.
    };
    static void Mult() { // (умножение)
        counter++; // 11.
    };
    static void Div() { // (деления)
        counter++; // 11.
    };
};

int MyMath::counter = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "4 Лабораторная работа. Вопрос 4." << endl;

    // 1. Сделайте все поля в классе оружия закрытыми.

    // 2. Добавьте GET - методы для всех полей.

    // 3. Сделайте SET - метод для наносимого урона.

    // 4. Проверьте работу всех новых методов.

    Weapon axe("Топор", 7, 5);
    //cout << "Новое оружие: название - " << axe.name << endl; // error
    cout << "Новое оружие: название - " << axe.getName() << 
        ", наносимый урон - " << axe.getDamage() <<
        ", вес - " << axe.getWeight() << endl;

    axe.setDamage(5.25);
    cout << "Изменение урона у оружия " << axe.getName() <<
        " на - " << axe.getDamage() << endl;

    // 5. Создайте класс Characteristic, имеющий одно поле : силу.
    // Также добавьте конструктор, который будет инициализировать 
    // это поле переданным значением.

    // 6. Сделайте класс Characteristic дружественным для класса оружия.

    // 7. Создайте в классе Characteristic функцию GetDamage, 
    // принимающую оружие и возвращающую суммы силы и урон от 
    // переданного оружия.

    // 8. Проверьте созданный функционал, создав оружие, экземпляр 
    // класса Characteristic и вызвав его метод GetDamage.

    Weapon sword("Меч", 6, 6);
    Characteristic charact = Characteristic(8);
    cout << "Сумма силы [8] и урона для оружия (Меч, [6], 6) - " <<
        charact.getDamage(sword) << endl;

    // 9. Создайте класс MyMath, имеющий 4 статических метода : 
    // Add(сложение), Sub(вычитание), Mult(умножение) и Div(деления).

    // 10. Добавьте статическое поле в класс MyMath, в котором будет 
    // храниться количество вызовов статических методов.

    // 11. Исправьте все 4 метода так, чтобы в каждом делался 
    // инкремент созданной статической переменной.

    // 12. Проверьте все 4 метода, выведя результат их работы в консоль.

    MyMath::Add();
    MyMath::Sub();
    MyMath::Mult();
    MyMath::Div();

    /*
    cout << "Add(сложение) 2 + 2 = " << MyMath.Add() << endl;
    cout << "Sub(вычитание) 8 - 3.5 = " << MyMath.Sub() << endl;
    cout << "Mult(умножение) 4 * 3.75 = " << MyMath.Mult() << endl;
    cout << "Div(деление) 5 / 0.93 = " << MyMath.Div() << endl;
    */

    // 13. Проверьте значение статической переменной, выведя её 
    // в консоль. Её значение должно равняться количеству вызовов 
    // методов у класса MyMath.

    cout << "Методы класса MyMath вызваны - " << MyMath::counter << " раз." << endl;

    std::cout << "Hello World!\n";
}
