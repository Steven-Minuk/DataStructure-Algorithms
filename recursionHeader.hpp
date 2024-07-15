#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <iostream>
using namespace std;

class List
{
	private:
	int size;
	int* values;
	
	public:
	List();
	List(int size, int values[]);
	List(const List& list);
	~List();
	
	int getSize() const;
	string str() const;
	
	int& operator[](int index);
	int operator[](int index) const;
    bool operator==(const List& rhs) const;
    friend ostream& operator<<(ostream& out, const List& rhs);
};

class ListMemoryBoundsException : public exception
{
	public:
	explicit ListMemoryBoundsException(const string& message, int size, int index);
	~ListMemoryBoundsException();
	virtual const char* what() const throw();
	
	private:
	string message;
	int size;
	int index;
};

#endif