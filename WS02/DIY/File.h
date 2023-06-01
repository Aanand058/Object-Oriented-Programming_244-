/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation
   // of the records in the file
   int noOfRecords();

   bool read(int &population);

   bool read(char *postalCode);

}
#endif // !SDDS_FILE_H_
