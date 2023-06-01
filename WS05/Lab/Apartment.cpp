/***********************************************************************
// OOP244 Workshop 5 p1: tester program
//
// File  Apartment.cpp
// Version 1.0
// Date  summer of 2022
// Author  Kalimullah Jawad
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2022/10/06      peer review
--------------------------------------------------------------
Student Name: Aanand Aman
Student ID: 166125211
Email: aaman8@myseneca.ca 


   I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/






#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
    Apartment::Apartment(int number, double balance)
    {

        if (number >= 1000 && number <= 9999 && balance >= 0)
        {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Apartment::display() const
    {
        if (*this)
        {
            cout.width(4);
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else
        {
            cout << "Invld|  Apartment   ";
        }
        return cout;
    }
    Apartment::operator bool() const
    {

        if (m_number >= 1000 && m_number <= 9999 && m_balance >= 0)   //Validating the Apartment object.  
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Apartment::operator int() const
    {
        return this->m_number;
    }
    Apartment::operator double() const
    {
        return this->m_balance;
    }
    bool Apartment::operator~() const
    {
        if (this->m_balance < 0.00001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Apartment& Apartment::operator=(int num)
    {
        if ((this) &&(num >= 1000 && num <= 9999))
        {
           
 
                this->m_number = num;
        }
        else
        {
            this->m_number = -1;
            this->m_balance = 0.0;
        }
        
        return *this;
    }
    Apartment& Apartment::operator=(Apartment& rhsApartment)
    {
        if ((this) && (rhsApartment))
        {
            int tempSwapNum = 0; // Creating temp variables to store the values of this object and swap with rhsApartmet object
            double tempSwapRent = 0.0;

            tempSwapNum = this->m_number;
            tempSwapRent = this->m_balance;

            this->m_number = rhsApartment.m_number;
            this->m_balance = rhsApartment.m_balance;

            rhsApartment.m_number = tempSwapNum;
            rhsApartment.m_balance = tempSwapRent;
        }

        return *this;
    }
    Apartment& Apartment::operator+=(double rent)
    {
        if ((this) && (rent > 0))
        {
                this->m_balance = this->m_balance + rent;
            
        }
        return *this;
    }
    Apartment& Apartment::operator-=(double rent)
    {
        if ((this) && (rent > 0) && (this->m_balance > rent))
        {
                this->m_balance = this->m_balance - rent;
            
        }
        return *this;
    }
    Apartment& Apartment::operator<<(Apartment& rhsApartment)
    {
        if ((this) && (rhsApartment))
        {
            if (this->m_number != rhsApartment.m_number)
            {
                this->m_balance = this->m_balance + rhsApartment.m_balance;
                rhsApartment.m_balance = 0;
            }
        }
        return *this;
    }

    Apartment& Apartment::operator>>(Apartment& rhsApartment)
    {
        if ((this) && (rhsApartment))
        {
            if (this->m_number != rhsApartment.m_number)
            {

                rhsApartment.m_balance = this->m_balance + rhsApartment.m_balance;
                this->m_balance = 0.0;
            }
        }
        return *this;
    }
    double operator+(const Apartment& lhsApartment, const Apartment& rhsApartment)
    {
        if ((lhsApartment) && (rhsApartment))
        {
            double sumRent = 0;
            sumRent = double(lhsApartment) + double(rhsApartment);
            return sumRent;
        }
        else
        {
            return 0;
        }
    }
    double operator+=(double& rent, const Apartment& rhsApartment)
    {
        if (rhsApartment)
        {
            rent = rent + double(rhsApartment);
            return rent;
        }
        else
        {
            return 0;
        }
    }

}
