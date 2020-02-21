#include "tabstring.h"
#include <exception>
#include <string>

TabString::TabString()
{

}

size_t TabString::insert(size_t i, const char* field)
{
    std::string temp(field);
    return insert(i, temp);
}

size_t TabString::insert(size_t i, std::string& field)
{
    if ( i <= fields.size()) {
        fields.insert(fields.begin() + i, field);
        return i;
    }
    else {
        //если нужно добавить новое поле по индексу,
        //который находится за диапозоном,
        //то создать пустые поля до нужного индекса (расширение диапозона)
        for (size_t j = 0; j < i - fields.size(); j++) {
            push_back("");
        }

        fields.push_back(field);
    }
}

std::string& TabString::at(size_t i)
{
    if ( i < fields.size()) {
        return fields[i];
    }

    throw std::out_of_range("Cannot find index (in function TabString::at(size_t i))");
}

void TabString::push_back(const char* str)
{
    std::string temp(str);
    fields.push_back(temp);
}


void TabString::push_back(std::string str)
{
    fields.push_back(str);
}

size_t TabString::erase(size_t i)
{
    if ( i < fields.size()) {
        fields.erase(fields.begin() + i);
        return i;
    }
    else {
        throw std::out_of_range("Cannot find index (in function TabString::erase(size_t i))");
    }
}

size_t TabString::size() const
{
    return fields.size();
}

std::ostream& operator<< (std::ostream& out, const TabString& arg)
{
    for ( size_t i = 0; i < arg.size(); i++) {
        out << " |" << arg[i] << "| ";
    }

    out << std::endl;

    return out;
}

std::istream& operator>> (std::istream &in, TabString &arg)
{
    std::string tempStr;
    char tempChar;

    in >> std::noskipws;
    in >> tempChar;

    //поля отделяются только табуляцией
    //пробел - часть поля
    while(tempChar != '\n') {
        if ( tempChar == '\t') {
            arg.push_back(tempStr);
            tempStr.clear();
        }
        else {
            tempStr += tempChar;
        }

        in >> tempChar;
    }

    arg.push_back(tempStr);

    return in;
}
