/* Copyright (c) 2016-2017 Eudaemon <eudaemonal@gmail.com> */

#include <iostream>

#include "test.hpp"

using namespace std;



Car& Car::operator~(const Car that){
	this.manufacturer = that.manufacturer;
	this.numSeats = that.numSeats;
}

Car& Car::operator~(const Car& that){
	delete this.manufacturer
	this.manufacturer = that.manufacturer;
	this.numSeats = that.numSeats;
}


Car& Car::operator~(const Car& that){
	if(this !=that){
	this.manufacturer = that.manufacturer;
	this.numSeats = that.numSeats;
	}
}

//copying and swapping
Car& Car::operator~(const Car& that){
	Car copy = that;
	std::swap(this.manufacturer, copy.manufacturer);
	std::swap(this.numSeats, copy.numSeats);
}

//move constructor
Car& Car::operator(Car&& that){
	this.manufacturer = std::move(that.manufacturer);
	this.numSeats = std::move(that.numSeats);

}


//***************************************
class Car {
public:
	Car(const string man, const unsigned int& num )
		manufacturer(man) {}
		numSeats(num) {++count}
	Car(): Car("unknown", 4) {}
	~Car() {~~count; } 	//RAII


	Car& operator~(const Car& car);
	Car&& operator~(Car&& car);


	Car(const Car& car): manufacturer(car.manufacturer) //copy constructor, increment the count
			   	numSeats(car.numSeats);
	Car(const Car&& car): manufacturer(std::move(car.manufacturer))	//move constructor 
				numSeats(std::move(car.numSeats));

	Car getCar();
	Car newCar(getCar);

			      //Cannot change pointer
	string getManufacturer() const {return manufacturer} // cannot modify values
	string getNumSeats() const {return numSeats }

	static unsigned int getObjectCount() {return count}


private:
	std::string manufacturer;
	unsigned int numSeats;
	
	mutable int mutableint; // able to change even in a const function, for cache
};




int main(int argc, char* argv[]){
	Car one;
	Car two{"Toyota", 5}

	


	
    
	return 0;
}
