#ifndef TABSTRING_H
#define TABSTRING_H

#include <vector>
#include <iostream>

class TabString
{
public:
    TabString();

    //insert(size_t i, T field), i - место вставки (перед каким индексом),
    //поля после сдвигаются
    //шаблон функции вставки для обработки "цифровых" полей
    template < typename T > size_t insert(size_t i, T field){
        std::string temp = std::to_string(field);
        return insert(i, temp);
    }

    size_t insert(size_t i, const char* field);
    size_t insert(size_t i, std::string& field);

    //поиск поля по индексу с проверкой
    //возвращает ссылку на найденное поле
    //используется при редактировании поля
    std::string& at(size_t i);

    //добавить поле в конец
    void push_back(const char* str);
    void push_back(std::string str);

    //удалить поле по индексу с проверкой
    size_t erase(size_t i);

    size_t size() const;

    //прямой доступ к полю по индексу
    //проверка на пользователе
    //без возможности изменения поля
    const std::string operator[] (size_t i) const { return fields[i]; }

private:
    std::vector<std::string> fields;
};

std::ostream& operator<< (std::ostream& os, const TabString& arg);
std::istream& operator>> (std::istream &in, TabString &arg);

#endif // TABSTRING_H
