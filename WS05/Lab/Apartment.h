/***********************************************************************
// OOP244 Workshop 5 p1: tester program
//
// File  Apartment.h
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


#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
    class Apartment
    {
        int m_number = -1;
        double m_balance = 0.0;

    public:

        Apartment(int number, double balance);
        std::ostream& display() const;

        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;
       

        Apartment& operator=(int num);
        Apartment& operator=(Apartment& rhsApartment);

        Apartment& operator+=(double rent);
        Apartment& operator-=(double rent);

        Apartment& operator<<(Apartment& rhsApartment);
        Apartment& operator>>(Apartment& rhsApartment);

         friend double operator+(const Apartment& lhsApartment, const Apartment& rhsApartment);
         friend double operator+=(double& rent, const Apartment& rhsApartment);
    };

}

#endif // SDDS_APARTMENT_H_