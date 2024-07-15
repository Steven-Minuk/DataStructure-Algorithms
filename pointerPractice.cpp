#include "pointerPractice.hpp"

using namespace std;

static int nextLargeIntegerId = 1;

LargeInteger::LargeInteger()
{
	id = nextLargeIntegerId++;
	numDigits = 1;
	digit = new int[numDigits];
	digit[0] = 0;
}

LargeInteger::LargeInteger(int value)
{
	id = nextLargeIntegerId++;
	numDigits = (int)log10((double)value) + 1;
	digit = new int[numDigits];
	int nextDigit;
	for(int digitIndex = 0;digitIndex<numDigits; digitIndex++)
	{
		nextDigit = value % 10;
		digit[digitIndex] = nextDigit;
		value = value / 10;
	}
}

LargeInteger::LargeInteger(int numDigits, const int digit[])
{
	this->digit = new int[numDigits];
	this->numDigits = numDigits;
	for(int i = 0; i<numDigits; i++)
	{
		this->digit[i] = digit[i];
	}
}

LargeInteger::~LargeInteger()
{
	delete[] this->digit;
}

string LargeInteger::tostring() const
{
	ostringstream ss;
	for(int i = numDigits - 1; i>=0; i--)
	{
		ss << digit[i];
	}
	return ss.str();
}

int LargeInteger::maxDigits(const LargeInteger& other) const
{
	if(numDigits > other.numDigits)
	{
		return numDigits;
	}
	else
	{
		return other.numDigits;
	}
}

int LargeInteger::digitAtPosition(int position)
{
	if(0<= position && position < numDigits)
	{
		return digit[position];
	}
	return 0;
}

void LargeInteger::appendDigit(int value)
{
  if (value != 0)
  {
    int* newDigit = new int[numDigits + 1];
    for (int i = 0; i < numDigits; i++)
    {
      newDigit[i] = digit[i];
    }
    if (digit != nullptr)
    {
      delete[] digit;
    }
    digit = newDigit;
    digit[numDigits] = value;
    numDigits += 1;
  }
}

LargeInteger& LargeInteger::add(LargeInteger& other)
{
  int numNewDigits = maxDigits(other);
  int* newDigits = new int[numNewDigits];
  int newDigit;
  int carry = 0;
  for (int i = 0; i < numNewDigits; i++)
  {
    newDigit = this->digitAtPosition(i) + other.digitAtPosition(i) + carry;
    carry = newDigit / 10;
    newDigit = newDigit % 10;
    newDigits[i] = newDigit;
  }

  LargeInteger* result = new LargeInteger(numNewDigits, newDigits);
  result->appendDigit(carry);

  return *result;
}
