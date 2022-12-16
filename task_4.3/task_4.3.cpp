#include <iostream>
#include <Windows.h>
#include "Weapon.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "4 Лабораторная работа. Вопрос 3." << endl;

    Weapon knife;
    knife.outputData();
    cout << endl;
}
