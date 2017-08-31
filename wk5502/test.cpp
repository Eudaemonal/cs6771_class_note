/**
	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
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

class Car {
public:
	Car(std::string s, unsigned int i): manufacturer{s}, numSeats{i} {objectCount++;};
	Car(): Car{"generic", 4} {};
	~Car() {objectCount--;};

	Car(const Car& c);	//copy constructor
	Car(const Car&& c);	//move constructor

	Car& operator=(const Car& c);
	Car& operator=(const Car&& c);

	
	std::string getManufacturer() const { return manufacturer; }
	unsigned int getNumSeats() const { return numSeats; } 
	static unsigned int getObjectCount() { return objectCount; }
private:
	std::string manufacturer;
	unsigned int numSeats;
	static unsigned int objectCount;
};

unsigned int Car::objectCount = 0;



Car::Car(const Car& c) {
	manufacturer = c.manufacturer;
	numSeats = c.numSeats;
	objectCount++;
}

Car::Car(const Car&& c){
	manufacturer = std::move(c.manufacturer);
	numSeats = std::move(c.numSeats);
	objectCount++;
}

Car& Car::operator=(const Car& c) {
	manufacturer = c.manufacturer;
	numSeats = c.numSeats;
	return *this;
}

Car& Car::operator=(const Car&& c) {
	manufacturer = std::move(c.manufacturer);
	numSeats = std::move(c.numSeats);
	return *this;
}




int main(int argc, char* argv[]){
	Car one;
	Car two{"Toyota",5};
	
	std::cout << "1: "<<Car::getObjectCount() << std::endl;

	Car* three = new Car{};
	std::cout <<"2: "<< Car::getObjectCount() << std::endl;
	delete three;
	std::cout <<"3: "<< Car::getObjectCount() << std::endl;

	Car four{two};
	std::cout <<"4: "<< Car::getObjectCount() << std::endl;

	Car five = std::move(one);
	std::cout <<"5: "<< Car::getObjectCount() << std::endl;
	
	Car six{std::move(two)};
	std::cout <<"6: "<< Car::getObjectCount() << std::endl;

	four = six;
	std::cout <<"7: "<< Car::getObjectCount() << std::endl;
	std::cout <<"7: "<< four.Car::getNumSeats() << std::endl;

	five = std::move(six);
	std::cout << "8: " << Car::getObjectCount() << std::endl;

	
	return 0;
}
