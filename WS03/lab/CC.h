
/***********************************************************************
// OOP244 Workshop 3 p1: tester program
//
// File	CC.h
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date 29 Sept 2022           Reason
// Student Id: 166125211 
// Email: aaman8@myseneca.ca 
//

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

#define NAMELEN 71
namespace sdds
{
    class CC
    {
    private:
        char *m_name;
        short m_cvv;
        short m_exMM;
        short m_exYY;
        unsigned long long m_ccNum;

        bool validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void prnNumber() const;

    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char *name, unsigned long long cc_no, short ccv, short expMon, short expYear);
        bool read();
        void display(int row = 0) const;
    };

}

#endif