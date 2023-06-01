/***********************************************************************
// OOP244 Workshop 5 p2: tester program
//
// File  Mark.cpp
// Version 1.0
// Date  2022/10/10
// Author  Aanand Aman
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date  17 OCT 2022          Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Mark.h"

using namespace std;
namespace sdds
{
    Mark::Mark()
    {
        this->m_mark = 0;
    }
    Mark::Mark(int value)
    {
        if (value >= 0 && value <= 100)
        {
            this->m_mark = value;
        }
        else
        {
            this->m_mark = -1; // Setting as invalid state
        }
    }
    Mark::operator int() const
    {
        if (bool(this))
        {
            return this->m_mark;
        }
        else
        {
            return 0;
        }
    }

    bool Mark::valid(int value) const
    {
        if (value >= 0 && value <= 100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Mark::operator bool() const
    {
        if (this->m_mark >= 0 && this->m_mark <= 100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Mark::operator double() const
    {
        if (this->m_mark >= 0 && this->m_mark < 50)
        {
            return 0.0;
        }
        else if (this->m_mark >= 50 && this->m_mark < 60)
        {
            return 1.0;
        }
        else if (this->m_mark >= 60 && this->m_mark < 70)
        {
            return 2.0;
        }
        else if (this->m_mark >= 70 && this->m_mark < 80)
        {
            return 3.0;
        }
        else if (this->m_mark >= 80 && this->m_mark <= 100)
        {
            return 4.0;
        }
        else
        {
            return 0;
        }
    }
    Mark::operator char() const
    {

        if (this->m_mark >= 0 && this->m_mark < 50)
        {
            return 'F';
        }
        else if (this->m_mark >= 50 && this->m_mark < 60)
        {
            return 'D';
        }
        else if (this->m_mark >= 60 && this->m_mark < 70)
        {
            return 'C';
        }
        else if (this->m_mark >= 70 && this->m_mark < 80)
        {
            return 'B';
        }
        else if (this->m_mark >= 80 && this->m_mark <= 100)
        {
            return 'A';
        }
        else
        {
            return 'X';
        }
    }
    bool Mark::operator>(const Mark &rhsMark) const
    {
        if (this->m_mark > rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Mark::operator<(const Mark &rhsMark) const
    {
        if (this->m_mark < rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Mark::operator>=(const Mark &rhsMark) const
    {
        if (this->m_mark >= rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Mark::operator<=(const Mark &rhsMark) const
    {
        if (this->m_mark <= rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Mark::operator==(const Mark &rhsMark) const
    {
        if (this->m_mark == rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Mark::operator!=(const Mark &rhsMark) const
    {
        if (this->m_mark != rhsMark.m_mark)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Mark &Mark::operator++()
    {
        if (bool(this))
        {
            this->m_mark++;
        }
        return *this;
    }
    Mark &Mark::operator--()
    {
        if (bool(this))
        {
            this->m_mark--;
        }

        return *this;
    }
    Mark Mark::operator++(int)
    {
        Mark tempMark = *this;
        if (bool(*this))
        {
            this->m_mark++;
        }
        return tempMark;
    }

    Mark Mark::operator--(int)
    {
        Mark tempMark = *this;
        if (bool(*this))
        {
            this->m_mark--;
        }
        return tempMark;
    }
    bool Mark::operator~() const
    {
        if (this->m_mark >= 50 && this->m_mark <= 100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Mark &Mark::operator=(const int value)
    {
        if (valid(value))
        {
            this->m_mark = value;
            return *this;
        }
        else
        {
            this->m_mark = value;
            return *this;
        }
    }
    Mark &Mark::operator+=(const int value)
    {
        if (valid(value))
        {

            this->m_mark = this->m_mark + value;
            if (bool(this))
            {
                return *this;
            }
            else
            {

                return *this;
            }
        }
        else
        {
            return *this;
        }
    }
    Mark &Mark::operator-=(const int value)
    {
        if (valid(value) && this->m_mark > value)
        {
            this->m_mark = this->m_mark - value;
            if (this->m_mark < 0)
            {
                this->m_mark = 0;
                return *this;
            }
            return *this;
        }
        else
        {
            this->m_mark = 0;
            return *this;
        }
    }
    int operator+=(int &val1, const Mark &rhsMark)
    {

        if (bool(rhsMark))
        {
            val1 = val1 + int(rhsMark);
            return val1;
        }
        else
        {
            return val1;
        }
    }

    int operator-=(int &val1, const Mark &rhsMark)
    {

        if (bool(rhsMark))
        {
            val1 = val1 - int(rhsMark);
            return val1;
        }
        else
        {
            return val1;
        }
    }

    Mark &Mark::operator<<(Mark &rhsMark)
    {

        if ((this))
        {
            this->m_mark = this->m_mark + rhsMark.m_mark;
            rhsMark.m_mark = 0;
        }
        return *this;
    }

    Mark &Mark::operator>>(Mark &rhsMark)
    {

        if ((this) && (rhsMark))
        {
            rhsMark.m_mark = rhsMark.m_mark + this->m_mark;
            if (bool(rhsMark))
            {
                this->m_mark = 0;
                return *this;
            }
        }
        return *this; 
    }
    Mark Mark::operator+(const int value) const
    {
        Mark sum = *this;
        sum.m_mark = this->m_mark + value;
        if (bool(sum))
        {
            return sum;
        }
        else
        {
            sum.m_mark = -1; // Set as -1 to make it invalid otherwise it was printing 0
            return sum;
        }
    }
    Mark Mark::operator+(const Mark &rhsMark) const
    {
        Mark sum = *this;
        sum.m_mark = this->m_mark + rhsMark.m_mark;
        if (bool(this))
        {
            return sum;
        }
        else
        {
            sum.m_mark = -1;
            return sum;
        }
    }
    int operator+(const int value, const Mark &rhsMark)
    {
        int sum = 0;
        sum = value + int(rhsMark);
        if (sum > 0 && sum <= 100)
        {
            return sum;
        }
        else
        {
            return -1;
        }
    }
}
