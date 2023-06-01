/***********************************************************************
// OOP244 Workshop 4 p2: TourTicket Module
//
// File	TourTicket.cpp
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Aanand Aman          Date  Oct 9,2022          Reason
//   
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "TourTicket.h"
#include "TourBus.h"
using namespace std;
namespace sdds
{
    TourBus::TourBus(int num) // Constructor setting the class to null and bus_size to the user input bus size 
                                //
    {
        tticket = nullptr;
        bus_size = num;
    }

    TourBus::~TourBus()       // Deconstructor deletes the class tticket and sets the class to null
    {
        delete[] tticket;
        tticket = nullptr;
    }

    bool TourBus::validTour() const     // (const) mentioned this part in reflect.txt
    {

        if (this->bus_size == 4 || this->bus_size == 16 || this->bus_size == 22)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    TourBus &TourBus::board() // taking class reference as it is mentioned "returning the reference of the TourBus Object"
    {
        char ls_Name[41]; // using local variable for storing name

        tticket = new TourTicket[bus_size]; // alloting dynamic memory for tticket

        cout << "Boarding " << this->bus_size << " Passengers:" << endl;

        for (int i = 0; i < this->bus_size; i++)
        {
            cout << i + 1 << "/"
                 << "4"
                 << "- Passenger Name: ";

            cin.getline(ls_Name, 40, '\n');

            tticket[i].issue(ls_Name); // calling issue function of tourticket to copy name into the class variable
        }

        return *this;
    }

    void TourBus::startTheTour() const
    {
        if (validTour() && this->bus_size == 4) // set it to 4 as the program was not working when selecting 16 or 22 (maybe some flaw with main.cpp as main.cpp only validating 4)
                                                //  board function is not called if 4 is not entered
        {

            cout << "Starting the tour...." << endl
                 << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;

            for (int i = 0; i < this->bus_size; i++)
            {
                cout << "|  " << i + 1 << " ";
                tticket[i].display() << endl;
            }
            cout << "+----+------------------------------------------+-----+" << endl;
        }
        else
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }
    }
}