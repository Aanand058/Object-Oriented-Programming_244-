/* ------------------------------------------------------
Workshop 10 part 1

Filename: search.h
-----------------------------------------------------------
Name: Aanand Aman
Student ID: 166125211
EMail: aaman8@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/



#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

#include <iostream>
#include "Collection.h"

namespace sdds {
	

	template <typename T>

	bool search(T t[], int noOfElements, const char* keyValue, Collection<T>& collection);




	template<typename T>

	bool search(T t[], int noOfElements, const char* keyValue, Collection<T>& collection)
	{
		bool returnValue =0;

		for (int i = 0; i < noOfElements; i++) 
		{
			if (t[i] == keyValue) 
			{
				collection.add(t[i]);
				 returnValue = true;
			}
			
			
		}

		return returnValue;
		
	}

}
#endif
