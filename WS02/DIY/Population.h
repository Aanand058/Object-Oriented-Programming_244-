/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Population.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description


    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Revision History
// -----------------------------------------------------------
// Name  Aanand Aman           Date 25 Sept. 2022           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
    struct population
    {
        char m_postalCode[3];
        int m_data;
    };

    

    bool load(population&);

    bool load(const char filename[]);

    void display();

    void deallocateMemory();
      void sort();

}
#endif // SDDS_POPULATION_H_