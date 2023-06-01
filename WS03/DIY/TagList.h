/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	TagList.h
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
#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_

namespace sdds
{
    class TagList
    {
        class NameTag *w3p2_name_Original;

    public:
        void set();
        void set(int num);
        void add(const NameTag &nt);
        void print();
        void cleanup();
    };

}

#endif