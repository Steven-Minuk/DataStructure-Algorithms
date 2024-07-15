#include "recursionHeader.hpp"
#include <iostream>
#include <sstream>
using namespace std;

List::List()
{
  size = 0;
  values = nullptr;
}

List::List(int size, int values[])
{
  this->size = size;
  this->values = new int[size];

  for (int index = 0; index < size; index++)
  {
    this->values[index] = values[index];
  }
}

List::List(const List& list)
{
  size = list.size;
  values = new int[size];

  for (int index = 0; index < size; index++)
  {
    values[index] = list.values[index];
  }
}

List::~List()
{
  if (values != nullptr)
  {
    delete[] values;
  }
}

int List::getSize() const
{
  return size;
}

string List::str() const
{
  ostringstream out;

  out << "<list> size: " << size << " [ ";

  for (int index = 0; index < size; index++)
  {
    out << values[index] << " ";
  }
  out << "]";

  return out.str();
}

int& List::operator[](int index)
{
  if ((index < 0) or (index >= size))
  {
    ostringstream out;
    out << "Error: illegal bounds access, list size: " << size << " tried to access index address: " << index;

    throw ListMemoryBoundsException(out.str(), size, index);
  }

  return values[index];
}

int List::operator[](int index) const
{
  if ((index < 0) or (index >= size))
  {
    ostringstream out;
    out << "Error: illegal bounds access, list size: " << size << " tried to access index address: " << index;

    throw ListMemoryBoundsException(out.str(), size, index);
  }

  return values[index];
}

bool List::operator==(const List& rhs) const
{
  if (size != rhs.size)
  {
    return false;
  }

  for (int index = 0; index < size; index++)
  {
    if (values[index] != rhs.values[index])
    {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& out, const List& rhs)
{
  out << rhs.str();

  return out;
}

ListMemoryBoundsException::ListMemoryBoundsException(const string& message, int size, int index)
{
  this->message = message;
  this->size = size;
  this->index = index;
}

ListMemoryBoundsException::~ListMemoryBoundsException() {}

const char* ListMemoryBoundsException::what() const throw()
{
  return message.c_str();
}