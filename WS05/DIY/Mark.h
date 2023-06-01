/***********************************************************************
// OOP244 Workshop 5 p2: tester program
//
// File  Mark.h
// Version 1.0
// Date  2022/10/10
// Author  Aanand Aman
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date  20 OCT 2022          Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
        int m_mark;

    public:
        Mark();
        Mark(int value);

        bool valid( int value) const; //created for validating the int value 

        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;

        bool operator>(const Mark &rhsMark) const;
        bool operator<(const Mark &rhsMark) const;
        bool operator>=(const Mark &rhsMark) const;
        bool operator<=(const Mark &rhsMark) const;
        bool operator==(const Mark &rhsMark) const;
        bool operator!=(const Mark &rhsMark) const;

        Mark &operator++();
        Mark &operator--();
        Mark operator++(int);
        Mark operator--(int);
        bool operator~() const;

        Mark &operator=(const int value);
        Mark &operator+=(const int value);
        Mark &operator-=(const int value);

        Mark operator+(const int value) const;
        Mark operator+(const Mark &rhsMark) const;

        Mark &operator<<(Mark &rhsMark);
        Mark &operator>>(Mark &rhsMark);
        // Mark &operator+(const int value);
        friend int operator+(const int value, const Mark &rhsMark);
        friend int operator+=(int &val1, const Mark &rhsMark);
        friend int operator-=(int &val1, const Mark &rhsMark);
    };

}

#endif
