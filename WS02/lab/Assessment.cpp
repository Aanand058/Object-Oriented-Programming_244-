/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/17
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Aanand Aman          Date: 23 Sept. 2022           Reason
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Assessment.h"
#include "Utils.h"

using namespace std;
namespace sdds
{

	bool read(int &value, FILE *fptr)
	{
		if (fscanf(fptr, "%d", &value) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(double &value, FILE *fptr)
	{
		if (fscanf(fptr, "%lf", &value) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(char *cstr, FILE *fptr)
	{
		if (fscanf(fptr, ",%60[^\n]\n", cstr) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(Assessment &asmnt, FILE *fptr)
	{

		double mark = 0;   // temp variabale to store the decimal values
		char temp[60 + 1]; // temp variable to store the corresponding title

		bool markRead = read(mark, fptr);
		bool tempRead = read(temp, fptr);

		if (markRead && tempRead)
		{

			asmnt.m_mark = new double; // allocating dynamince memory for copying values
			asmnt.m_title = new char[(strlen(temp) + 1)];

			*(asmnt.m_mark) = mark;
			strcpy(asmnt.m_title, temp);

			return true;
		}

		return false;
	}
	void freeMem(Assessment *&aptr, int size)
	{

		for (int i = 0; i < size; i++)
		{
			delete aptr[i].m_mark; // deleting inner dynamic memory of struct
			delete[] aptr[i].m_title;
		}
		for (int i = 0; i < size; i++)
		{
			aptr[i].m_mark = nullptr; // setting all the memory to nullptr
			aptr[i].m_title = nullptr;
		}
		delete[] aptr; // deleting dynamic memory of struct
		aptr = nullptr;
	}

	int read(Assessment *&aptr, FILE *fptr)
	{

		int i = 0;
		int noOfRec = 0;
		bool validation = true;
		// validate to read the records of file

		read(noOfRec, fptr); // reading the no of records of the file for looping

		aptr = new Assessment[noOfRec]; // creating dynaminc array

		for (i = 0; i < noOfRec && validation; i++)
		{
			validation = read(aptr[i], fptr);
		}

		if (i != noOfRec) // checks the codition to match the no. of records in file with actual no. of data in file
		{
			freeMem(aptr, i - 1); // doing i -1 as the for loop (i++) will incrment the value of i by 1.
			return 0;
		}
		else
		{
			return i; //returning the size of array 
		}
	}

}
