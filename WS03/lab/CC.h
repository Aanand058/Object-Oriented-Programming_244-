

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

#define NAMELEN 71
namespace sdds
{
    class CC
    {
    private:
        char *m_name;
        short m_cvv;
        short m_exMM;
        short m_exYY;
        unsigned long long m_ccNum;

        bool validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void prnNumber() const;

    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char *name, unsigned long long cc_no, short ccv, short expMon, short expYear);
        bool read();
        void display(int row = 0) const;
    };

}

#endif