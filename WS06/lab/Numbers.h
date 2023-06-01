/***********************************************************************
// OOP244 Workshop 6 p1: tester program
//
// File Numbers.h

// Name Aanand Aman           Date Oct 25 2022           Reason

In this code, I got help from my classmate Chow ka ho email: kchow25@myseneca.ca regarding the sort method adn operator + and -.
He provided me these lines of code: 
const bool ASCENDING = true;
    const bool DESCENDING = false;
Numbers asc = Numbers(*this);
        asc.sort(ASCENDING);
         Numbers asc = Numbers(*this);
        asc.sort(ASCENDING);
/////////////////////////////////////////////////////////////////
***********************************************************************/



#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);

        //Implemented by me 
        Numbers& sort(bool ascending);

    public:
        Numbers();
        Numbers(const char* filename);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();


        //Implemented by me 
        Numbers(const Numbers& toCopyFrom);

        Numbers& operator=(const Numbers& toCopyFrom);

        Numbers operator-()const;

        Numbers operator+()const;

        int numberCount() const;

        bool load();

        void save();

        Numbers& operator+=(double value);

        std::ostream& display(std::ostream& ostr= std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

