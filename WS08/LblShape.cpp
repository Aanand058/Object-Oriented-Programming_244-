
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "LblShape.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    char* LblShape::label() const
    {
        return this->m_label;
    }

    LblShape::LblShape()
    {
        if (this->m_label != nullptr) {
            this->m_label = nullptr;
        }

    }

    LblShape::LblShape(const char* label)
    {
        if (label != nullptr) {
            this->m_label = new char[(strlen(label) + 1)];
            strcpy(this->m_label, label);
        }
    }

    LblShape::~LblShape()
    {
        delete[] this->m_label;
        this->m_label = nullptr;
    }


    //Reads a comma-delimited Cstring form istream:
    void LblShape::getSpecs(std::istream& is)
    {
        char read[50];
        is.get(read, 50, ',');
        is.ignore(1000, ',');
        
        delete[] this->m_label;

        this->m_label = new char[strlen(read) + 1];
        strcpy(this->m_label, read);
    }



}