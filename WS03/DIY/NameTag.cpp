/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	NAmeTag.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date  Oct. 3 2022          Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "NameTag.h"
#include "TagList.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    void NameTag::set(const char *name)
    {
        strcpy(w3p2_name, name);
    }

    void NameTag:: display()  
    {
        cout << this->w3p2_name;
    }
}