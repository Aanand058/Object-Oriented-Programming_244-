
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
