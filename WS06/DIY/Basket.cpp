

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Basket.h"

using namespace std;

namespace sdds {


	void Basket::Empty()
	{
		 this->m_fruit = nullptr;
		this->m_fruitSize = 0;
		this-> m_price = 0.0;
	}

	bool Basket::valid(Fruit* fruit, int fruitArrSize1, double price) const
	{
		if (fruit != nullptr && fruitArrSize1 > 0 && price > 0.0) {
			return true;
		}
		else { return false; }
		
	}

	Basket::Basket()
	{
		Empty();
	}

	Basket::Basket(Fruit* fruitSrc, int fruitArrSize, double price)
	{
		if (valid(fruitSrc, fruitArrSize, price)) {
			this->m_fruitSize = fruitArrSize;
			this->m_price = price;

			this->m_fruit = new Fruit[fruitArrSize];

			for (int i = 0; i < fruitArrSize; i++) {
				this->m_fruit[i] = fruitSrc[i];
			}

		}

	}

	Basket::Basket(const Basket& toCopyFrom)
	{
		Empty();
		*this = toCopyFrom;
	}

	Basket& Basket::operator=(const Basket& toCopyFrom)
	{
		if (this != &toCopyFrom) {

			delete[] this->m_fruit;
			this->m_fruit = nullptr;

			this->m_fruitSize = toCopyFrom.m_fruitSize;
			this->m_price = toCopyFrom.m_price;

			this->m_fruit = new Fruit[this->m_fruitSize];

			for (int i = 0; i < this->m_fruitSize; i++) {
				this->m_fruit[i] = toCopyFrom.m_fruit[i];
			}


		}
		return *this;
	}

	Basket::~Basket()
	{
		delete[] this->m_fruit;
		this->m_fruit = nullptr;

	}

	void Basket::setPrice(double price)
	{
		if (price > 0.0) {
			this->m_price = price;
		}
	}

	Basket::operator bool() const
	{
		if (this->m_fruitSize > 0) { return true; }
		else { return false; }
	}

	Basket& Basket::operator+=(Fruit fruit)
	{
		Fruit* tempFruit = nullptr;
		tempFruit = new Fruit[this->m_fruitSize +1];

		for (int i = 0; i < this->m_fruitSize; i++) {
			tempFruit[i]=this->m_fruit[i];
		}

		tempFruit[this->m_fruitSize] = fruit; 
		this->m_fruitSize++;

		delete[] this->m_fruit;

		this->m_fruit = tempFruit; 

		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const Basket& Basket)
	{
		if (!bool(Basket)) {
			ostr << "The basket is empty!" << endl;
		}
		else {
			ostr << "Basket Content:" << endl;
			for (int i = 0; i < Basket.m_fruitSize; i++) {
				ostr.width(10);
				ostr.setf(ios::right);
				ostr << Basket.m_fruit[i].m_name << ": ";
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << Basket.m_fruit[i].m_qty << "kg" << endl;

			}
			ostr << "Price: ";
			ostr.precision(2);
			ostr << Basket.m_price << endl;
		}
		return ostr;
	}
}