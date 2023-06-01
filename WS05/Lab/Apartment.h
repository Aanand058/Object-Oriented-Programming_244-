


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