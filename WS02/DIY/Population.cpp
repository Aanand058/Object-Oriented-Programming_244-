/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Population.cpp
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name  Aanand Aman           Date 25 Sept. 2022           Reason
//

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds
{

    population *population1 = nullptr;  //initializing the structure
    int noOfRec = 0; // count the total no. of records in the file 
    int validation = 0; // used for the validation to match the records with the data present in the file 
    int i = 0; // for loop iteration 
    bool load(population &population1)
    {
        if (read(population1.m_postalCode) && read(population1.m_data) == 1)  // functions overload to read the population and postal code for confirmation 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool load(const char filename[])
    {

        if (openFile(filename)) // opens the file in read mode
        {
            noOfRec = noOfRecords();  
            population1 = new population[noOfRec]; //allocating dynamic memory for stroing the data of file 

            for (i = 0; i < noOfRec; i++)
            {
                load(population1[i]);
                validation++; 
            }

            if (validation != noOfRec) //cehcks if the records matches with the actual data in file 
            {

                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
        }
        else
        {
            cout << "Could not open data file:" << filename << endl;
        }
        closeFile();
        return 1;
    }
    void display()
    {
        int totalPOP = 0; // count the total population from the file 
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (i = 1; i <= noOfRec; i++)
        {
            cout << i << "- " << population1[i - 1].m_postalCode << ":  " << population1[i - 1].m_data << endl; 
        }
        for (i = 0; i < noOfRec; i++)
        {
            totalPOP = totalPOP + population1[i].m_data;
        }
        cout << "-------------------------" << endl;

        cout << "Population of Canada: " << totalPOP << endl;
    }

    void sort() // sorting the data in ascednig order 
    {
        int i, j;
        population temporary; //creating temp value to hold the changing values and later assign it correctly for sorting 
        for (i = noOfRec - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (population1[j].m_data > population1[j + 1].m_data) // checks if the first number of array is greater than second then it will swap those number and this will continue till all values get sorted 
                {
                    temporary = population1[j];
                    population1[j] = population1[j + 1];
                    population1[j + 1] = temporary;
                }
            }
        }
    }

    void deallocateMemory()
    {

        delete[] population1; //deleting the dynaminc memory 
        population1 = nullptr; //seting the memory to null 
    }

}