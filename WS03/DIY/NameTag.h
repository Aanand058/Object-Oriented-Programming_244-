/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	NameTag.h
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
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

#define NAMELEN 50
namespace sdds
{
    class NameTag
    {
    private:
        char w3p2_name[NAMELEN]; 

    public:
        void set(const char *name);
        void display();    //This one I created extra for displaying the each names when called by print in main.cpp 
    };
    
}

#endif