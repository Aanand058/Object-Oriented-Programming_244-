



#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);

        //Implemented by me 
        Numbers& sort(bool ascending);

    public:
        Numbers();
        Numbers(const char* filename);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();


        //Implemented by me 
        Numbers(const Numbers& toCopyFrom);

        Numbers& operator=(const Numbers& toCopyFrom);

        Numbers operator-()const;

        Numbers operator+()const;

        int numberCount() const;

        bool load();

        void save();

        Numbers& operator+=(double value);

        std::ostream& display(std::ostream& ostr= std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

