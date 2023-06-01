/***********************************************************************
// OOP244 Workshop 6 p1: tester program
//
// File Numbers.cpp

// Name Aanand Aman           Date Oct 25 2022           Reason

In this code, I got help from my classmate Chow ka ho // email: kchow25@myseneca.ca regarding  operator + and -.
He provided me these lines of code where i was unable to implent these functions propoerply. 
const bool ASCENDING = true;
    const bool DESCENDING = false;
Numbers asc = Numbers(*this);
        asc.sort(ASCENDING);
         Numbers asc = Numbers(*this);
        asc.sort(ASCENDING);
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"

using namespace std;
namespace sdds
{
    const bool ASCENDING = true;
    const bool DESCENDING = false;

    Numbers::Numbers()
    {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char *filename)
    {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load())
        {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }

    Numbers::~Numbers()
    {
        save();
        deallocate();
    }

    Numbers::Numbers(const Numbers &toCopyFrom)                  // copy constructor
    {
        isEmpty();
        this->m_isOriginal = false;
        *this = toCopyFrom;
    }

    Numbers &Numbers::operator=(const Numbers &toCopyFrom)      //Assginment operator 
    {
        if (this != &toCopyFrom)
        {
            delete[] this->m_numbers;
            this->m_isOriginal = false;
            this->m_numCount = toCopyFrom.m_numCount;
            if (toCopyFrom.m_numbers != nullptr)
            {
                this->m_numbers = new double[this->m_numCount];

                for (int i = 0; i < toCopyFrom.m_numCount; i++)
                {
                    this->m_numbers[i] = toCopyFrom.m_numbers[i];
                }
            }
        }
        return *this;
    }

    Numbers Numbers::operator-() const                     //sort for desecending values
    {
        Numbers desc = Numbers(*this);
        desc.sort(DESCENDING);
        return desc;
    }

    Numbers Numbers::operator+() const                  //sort for desecending values
    {
        Numbers asc = Numbers(*this);
        asc.sort(ASCENDING);
        return asc;
    }

    Numbers &Numbers::sort(bool ascending)
    {
        int i = 0;
        int j = 0;
        double tempValue = 0;
        if (ascending)                                                              //Ascending order 
        {
            for (i = this->m_numCount - 1; i > 0; i--)
            {
                for (j = 0; j < i; j++)
                {
                    if (this->m_numbers[j] > this->m_numbers[j + 1])
                    {
                        tempValue = this->m_numbers[j];
                        this->m_numbers[j] = this->m_numbers[j + 1];
                        this->m_numbers[j + 1] = tempValue;
                    }
                }
            }
        }       
        else                                                                   //Descending Order 
        {
            for (i = this->m_numCount; i != 0; --i)
            {
                for (j = this->m_numCount; --j != this->m_numCount - i;)
                {
                    if (this->m_numbers[j - 1] < this->m_numbers[j])
                    {
                        tempValue = this->m_numbers[j];
                        this->m_numbers[j] = this->m_numbers[j - 1];
                        this->m_numbers[j - 1] = tempValue;
                    }
                }
            }
        }
        return *this;
    }
    int Numbers::numberCount() const
    {
        int noOfLines = 0;
        ifstream file;

        char ch = '\0';
        file.open(this->m_filename);
        while (file.get(ch))
        {
            if (ch == '\n')
            {
                noOfLines++;
            }
        }
        file.close();

        return noOfLines;
    }

    bool Numbers::load()
    {
        int noOfLines = 0;
        if (this->m_numCount > 0)
        {
            this->m_numbers = new double[this->m_numCount];
            ifstream file;
            file.open(this->m_filename);

            if (file.is_open())
            {
                for (int i = 0; i < this->m_numCount; i++)
                {
                    file >> this->m_numbers[i];
                    noOfLines++;
                }
            }
        }
        if ( noOfLines == this->m_numCount )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Numbers::save()
    {
        if (this->m_isOriginal && !isEmpty())
        {
            ofstream file;
            file.open(this->m_filename);
            file.setf(ios::fixed);                                        //Using Precision for decimal values 
            file.precision(2);
            for (int i = 0; i < this->m_numCount; i++)
            {
                file << this->m_numbers[i] << endl;
            }
        }
    }

    Numbers &Numbers::operator+=(double value)
    {
        double *tempValue;
        tempValue = new double[this->m_numCount + 1];
        for (int i = 0; i < this->m_numCount; i++)
        {
            tempValue[i] = this->m_numbers[i];
        }
        tempValue[this->m_numCount] = value;
        this->m_numCount++;
        delete[] this->m_numbers;
        this->m_numbers = tempValue;
        return *this;
    }

    ostream &Numbers::display(ostream &ostr) const
    {
        
        if (isEmpty())
        {
            ostr << "Empty list";
        }
        else
        {
            ostr << "=========================" << endl;
            
            if (this->m_isOriginal)
            {
                ostr << this->m_filename << endl;
            }
            else
            {
                ostr << "*** COPY ***" << endl;
            }
            ostr.setf(ios::fixed);
            ostr.precision(2);
            for (int i = 0; i < this->m_numCount; i++)
            {
                ostr << this->m_numbers[i];
                if (i == (this->m_numCount - 1))
                {
                    ostr << endl;
                }
                else
                {
                    ostr << ", ";
                }
            }
            
            ostr << "-------------------------" << endl;
            ostr << "Total of " << this->m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    bool Numbers::isEmpty() const
    {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty()
    {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::deallocate()
    {
        delete[] m_filename;
        delete[] m_numbers;
    }

    void Numbers::setFilename(const char *filename)
    {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    double Numbers::average() const
    {
        double aver = 0.0;
        if (!isEmpty())
        {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const
    {
        double minVal = 0.0;
        if (!isEmpty())
        {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i])
                    minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const
    {
        double maxVal = 0.0;
        if (!isEmpty())
        {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i])
                    maxVal = m_numbers[i];
        }
        return maxVal;
    }

    std::ostream &operator<<(std::ostream &os, const Numbers &N)   //Implemented "std::" as it was not compiling previously. 
    {
        return N.display(os);
    }

    std::istream &operator>>(std::istream &istr, Numbers &N)
    {
        double tempValue = 0.0;
        istr >> tempValue;
        N += tempValue;
        return istr;
    }

}
