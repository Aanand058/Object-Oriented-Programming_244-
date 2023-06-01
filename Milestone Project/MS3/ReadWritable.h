

#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>



namespace sdds
{
	class ReadWritable {
		bool m_flag; 
	public:
		//Constructor
		ReadWritable();

		//an empty virtual destructor
		virtual ~ReadWritable();

		
		bool isCsv() const;

		void setCsv(bool value);

		//Pure Virtual functions
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& is)  = 0;
	


	};
	//Helper functions
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& r) ;
	std::istream& operator>>(std::istream& is, ReadWritable& r);





}
#endif // !
