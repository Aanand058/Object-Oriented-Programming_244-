


#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    //Implemented by me
    class Basket {
        Fruit* m_fruit;
        int m_fruitSize;
        double m_price;


        //Extra Private members 
       void Empty();  //Setting the elemnts to safe empty state 
        bool valid(Fruit* fruit, int fruitArrSize1, double price) const;   //validating if the numbers are greater than 0, and the array is not null
    public:
        //Constructors
        Basket();
        Basket(Fruit* Fruit, int fruitArrSize, double price);
        Basket(const Basket& toCopyFrom);

        //Operators
        Basket& operator =(const Basket& toCopyFrom);
        Basket& operator+=(Fruit fruit);
        operator bool() const;

        //Price Updating function
        void setPrice(double price);

        //Deconstructor
        ~Basket();


        //Friend Helper Function for displaying output 
        friend std::ostream& operator<<(std::ostream& ostr, const Basket& Basket);


        
    };
    
        


}
#endif // !SDDS_NUMBERS_H_

