/***********************************************************************
// OOP244 Workshop 3 p1: tester program
//
// File	CC.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Aanand Aman           Date 29 Sept 2022           Reason
// Student Id: 166125211
// Email: aaman8@myseneca.ca
// 

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include "CC.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

    bool CC::validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const
    {
        if ((name != nullptr && (strlen(name) > 2)) && (cardNo >= 4000000000000000 && cardNo <= 4099999999999999) &&
            (cvv > 99 && cvv < 1000) && (expMon >= 1 && expMon <= 12) && (expYear >= 22 && expYear <= 32))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void CC::prnNumber() const // function to divie 16-digit number into group of 4 digits
    {

        long long x = 1000000000000;
        // used 4 variables to store them differently
        int a1;
        int a2;
        int a3;
        int a4;

        a1 = m_ccNum / x;
        cout << a1;
        cout << " ";

        long long b = m_ccNum % x;
        a2 = b / 100000000;
        cout.width(4);
        cout.fill('0');
        cout.setf(ios::right);
        cout << a2 << " ";

        int c = b % 100000000;
        a3 = c / 10000;
        cout.width(4);
        cout << a3 << " ";
        a4 = c % 10000;
        cout.width(4);
        cout << a4;

        cout.fill(' ');
        cout.unsetf(ios::right);
    }

    void CC::set()
    {
        m_name = nullptr;
        m_cvv = 0;
        m_exMM = 0;
        m_exYY = 0;
        m_ccNum = 0;
    }
    void CC::cleanUp()
    {
        delete[] m_name;
        set();
    }

    bool CC::isEmpty() const
    {
        if (m_name == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void CC::set(const char *cc_name,
                 unsigned long long cc_no,
                 short cvv,
                 short expMon,
                 short expYear)
    {
        cleanUp();
        if (validate(cc_name, cc_no, cvv, expMon, expYear))
        {
            m_name = new char[NAMELEN]; // allocating dynamic memory for keeping the copy of the name in the name attribute
            strcpy(m_name, cc_name);
            m_ccNum = cc_no;
            m_cvv = cvv;
            m_exMM = expMon;
            m_exYY = expYear;
        }
    }

    bool CC::read()
    {
        bool ret = false; //using ret for returning the value true or false 
        char tempName[NAMELEN];
        unsigned long long tempCardNum;
        short tempCvv;
        short tempExMn;
        short tempExYr;

        cleanUp();

        cout << "Card holder name: ";
        cin.getline(tempName, NAMELEN); // getting the length of name till maximum of 71(NAMELEN)

        if (!(cin.fail()))
        {
            cout << "Credit card number: ";
            cin >> tempCardNum;
            if (!(cin.fail()))
            {
                cout << "Card Verification Value (CVV): ";
                cin >> tempCvv;
                if (!(cin.fail()))
                {
                    cout << "Expiry month and year (MM/YY): ";
                    cin >> tempExMn;
                    cin.ignore();
                    cin >> tempExYr;
                    if (!(cin.fail()))
                    {
                        set(tempName, tempCardNum, tempCvv, tempExMn, tempExYr);
                        cin.ignore(1000, '\n'); // got this reference from the main.cpp file
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (isEmpty())
        {
            ret = false;
        }
        else
        {
            ret = true;
        }
        return ret;
    }

    void CC::display(int row) const
    {
        if (isEmpty())
        {
            cout << "Invalid Credit Card Record";
            cout << endl;
        }
        else if (row > 0)
        {
            char tempName[NAMELEN];
            strcpy(tempName, m_name, 30); // using this to truncate the name length to maximum of 30

            cout << "|";
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << row;
            cout.unsetf(ios::right);
            cout << " | ";
            cout.width(31);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << tempName;

            cout << "| ";
            prnNumber();
            cout << " | ";
            cout << m_cvv;
            cout << " | ";
            cout.width(2);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << m_exMM << "/" << m_exYY << " |" << endl;

            cout.unsetf(ios::right);
            cout.unsetf(ios::left);
        }

        else
        {

            cout << "Name: " << m_name << endl;
            cout << "Creditcard No: ";
            prnNumber();
            cout << endl;
            cout << "Card Verification Value: " << m_cvv << endl;
            cout << "Expiry Date: " << m_exMM << "/" << m_exYY << endl;
        }
    }
}