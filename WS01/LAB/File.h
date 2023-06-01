/*
*****************************************************************************
                              Workshop - 1 (LAB)
Full Name  : Aanand Aman
Student ID: 166125211
Email      : aaman8@myseneca.ca
Date of completion :

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H


#include<iostream>
#include "ShoppingRec.h"
// Your header file content goes here



bool openFileForRead();
bool openFileForOverwrite();
void closeFile();
bool freadShoppingRec(ShoppingRec* rec);
void fwriteShoppintRec(const ShoppingRec* rec);

#endif