
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE *fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Closes the open file
   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }
   bool read(int &population)
   {
      if (fscanf(fptr, "%d\n", &population) == 1)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   bool read(char *postalCode)
   {
      if (fscanf(fptr, "%[^,],", postalCode) == 1)
      {

         return true;
      }
      else
      {
         return false;
      }
   }

}