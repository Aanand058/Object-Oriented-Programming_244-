/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  main.cpp
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
#include "Population.h"
using namespace sdds;
// The Load, display and deallocateMemory functions are the mandatory 
// function to be created in part 2 of the lab

int main() {
   // if loading of the population recrods into the dynamic memroy is successful
   if(load("PCpopulations.csv")) {
      // display all the records
      display();
   }
   // in any case delete the dynmaic memory if it is allocated
   deallocateMemory();
   return 0;
}
