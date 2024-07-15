#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class LargeInteger
{
	public:
		LargeInteger();
		LargeInteger(int value);
		~LargeInteger();
		LargeInteger(int, const int*);
		string tostring() const;
		int maxDigits(const LargeInteger& other) const;
		int digitAtPosition(int);
		void appendDigit(int);
		LargeInteger& add(LargeInteger& other);
	
	private:
		int id;
		int numDigits;
		int* digit;
};