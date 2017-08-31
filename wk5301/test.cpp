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
#include <string>
#include "test.h"

/*

*/
bool Book::operator==(const Book& rhs){
	return  this->name == rhs.name &&
		this->author == rhs.author &&
		this->isbn == rhs.isbn &&
		this->price == rhs.price;

}


std::ostream operator << (std::stream &stream, const Book &book){
	stream << rhs.name << ", ";
	stream << rhs.author << ", ";
	stream << rhs.isbn << ", ";
	stream << rhs.price;
}


Book::operator std::string(){
	return this.author + " " + this.name;
}


bool Book::operator<(const Book &rhs){
	return this->isbn < rhs.isbn;
}

int main(int argc, char* argv[]){
	std::vector<Book> books;


	Book a("Harry", "JK", 133124, 17.40);
	Book b("Harry", "JK", 133124, 17.40);

	//************************************
	books.push_back({"Harry", "JK", 133124, 17.40});
	books.push_back({});
	books.push_back({});

	sort(books.begin(), books.end());
	for(it==books.begin(); it!=books;++it){
		std::cout << *it <<"\n";
	}


	// lambda 
	std::sort(books, begin(), books.end(),
		[] (const Book& lhs, const Book& rhs){
			return lhs.getPrice() < rhs.getPrice();
		}
		);


	// count books with price less than min
	double min = 50;
	std::cout << std::count_if(books, begin(), books.end(),
		[min] (const Book& lhs, const Book& rhs){
			return lhs.getPrice() < min;
		}
		);


	/* able to modify min inside function
	std::cout << std::count_if(books, begin(), books.end(),
		[&min] (const Book& lhs, const Book& rhs){
			return lhs.getPrice() < min;
		}
		);

	*/

	auto func = [min] (const Book& book){
		return book.getPrice < min
	}
	std::cout << std::count_if(books, begin(), books.end(),func);

	std::cout << (a==b) << "\n";
	std::cout << a <<"\n";
	std::cout << std::string(a) << "\n";
	

	return 0;
}
