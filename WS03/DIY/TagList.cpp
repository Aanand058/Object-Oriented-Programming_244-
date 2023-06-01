/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	TagList.cpp
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
    int namesInFile = 0;  // Keeping track of the number of entires in the taglist array 
    int p = 0; // Looping itertion
    void TagList::set()
    {
        w3p2_name_Original = nullptr;
    }
    void TagList::set(int num)
    {
        cleanup();
        w3p2_name_Original = new NameTag[num];
        namesInFile = num; 
    }
    void TagList::add(const NameTag &nt)
    {
        this->w3p2_name_Original[p] = nt;    
        p++;
    }

    void TagList::print()
    {
        for (p = 0; p < namesInFile; p++)
        {


            cout << "******************************" << endl;
            cout << "* ";
            cout.width(27);
            cout.setf(ios::left);
            this->w3p2_name_Original[p].display();
            cout << "*" << endl;
            cout << "******************************" << endl;
            cout.unsetf(ios::left);
        }
    }

    void TagList::cleanup()
    {
        delete[] w3p2_name_Original;
        set();
    }
}
