#include <iostream>
#include "tabstring.h"
#include <exception>

using namespace std;

int main()
{
    try {
        TabString tStr;
        cin >> tStr;

        cout << tStr << endl;

        //изменение 0-го поля
        tStr.at(0) = "Changed";
        cout << tStr << endl;

        //вставка на 0, 3, 6 место
        //разных полей
        tStr.insert(0, "New");
        tStr.insert<int>(3, 3);
        tStr.insert<double>(6, 12.54);
        cout << tStr << endl;

        //удаление 4-го поля
        tStr.erase(4);
        cout << tStr << endl;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
