
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
