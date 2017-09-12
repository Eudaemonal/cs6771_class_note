/**	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
	test.cpp
	Purpose:

	@author: Eudaemon
	@version:  
*/
/**
	

	@param
	@return 
*/


#include <iostream>
#include "test.h"

class Person{
	public:
		enum PersonType {ADULT, CHILD,SENIRO};
		void setPersonType(PersonType person_type);
		PersonType getPersonType();
	private:
		PersonType _person_type;
};


void Person::setPersonType(PersonType person_type){
	_person_type = person_type;
}

auto Person::getPersonType()->PersonType{
	return _person_type;
}



int main(int argc, char* argv[]){
	Person p;
	p.setPersonType(Person::CHILD);

	std::cout << p.getPersonType() <<std::endl;
	

	return 0;
}
