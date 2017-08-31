#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>


class Book {
public:
	Book(const string name, const string& author, const int& isbn, const double &price):
		name(name), author(author), isbn(isbn), price(price){}
	bool operator==(const Book& rhs)

	bool operator==(const int& isbn);
	friend bool ioerator==(const int& isbn, const Book& rhs);
	//or
	friend bool ioerator==(const Book& rhsconst int* i);

	friend std::ostream operator<< (std::stream& stream, const &Book book); //Use: stream << Book
	
	operator std::string();

	//compare by isbn
	bool operator<(const Book &rhs);
	
  // getters
  int getIsbn() const { return isbn; }
  double getPrice() const  { return price; }
private:
  std::string name;
  std::string author;
  int isbn;
  double price;
};




#endif
