
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include "ReadWritable.h"

using namespace std;
namespace sdds
{


	ReadWritable::ReadWritable()
	{
		this->m_flag = false;
	}

	ReadWritable::~ReadWritable()
	{
	}


	bool ReadWritable::isCsv() const
	{

		return this->m_flag;
	}

	void ReadWritable::setCsv(bool value)
	{
		this->m_flag = value;

	}

	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& r)
	{
		r.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& r)
	{
		r.read(is);
		return is;
	}

}