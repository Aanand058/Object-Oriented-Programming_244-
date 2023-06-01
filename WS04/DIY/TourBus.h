/***********************************************************************
// OOP244 Workshop 4 p2: TourTicket Module
//
// File	TouBus.h
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date Oct 9,2022            Reason
//   
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include <iostream>
namespace sdds
{
   class TourBus
   {
      class TourTicket *tticket;
      int bus_size;

   public:
      TourBus(int num);
      ~TourBus();


      bool validTour() const;
      TourBus& board();
      void startTheTour() const;
   };
}
#endif // !SDDS_TOURTICKET_H_
