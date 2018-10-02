#ifndef __STRING_H__
#define __STRING_H__

#include <cstring>

typedef unsigned int uint;

class String {

public:
	//Constructors
	String() {}

	String(const char* string) : 
		num_allocated(strlen(string)), 
		str(new char[num_allocated + 1])
	{
		strcpy(str, string);
	}

	String(const String &string) : 
		num_allocated(string.num_allocated),
		str(new char[num_allocated + 1])
	{
		strcpy(str, string.str);
	}
	
	//Destructor
	~String() {
		clear();
	}

	//Methods
	bool is_empty() {
		return num_allocated == 0;
	}
	
	void clear() {
		delete str;
		str = nullptr;
		num_allocated = 0;
	}	

	uint allocatedSpace() {
		return num_allocated;
	}
	
	//Operators
	void operator+=(String &string) {
		uint newAllocated = num_allocated + strlen(string.str);
		char* newString = new char[newAllocated + 1];
		strcpy(newString, str);
		strcat(newString, string.str);
		clear();
		num_allocated = newAllocated;
		str = newString;
	}

	void operator=(String &string) {
		num_allocated += strlen(string.str);
		str = string.str;
	}

	bool operator==(String &string) const {
		return (str == string.str);
	}

	String operator+(String &string) {
		String newString(str);
		newString += string;
		return newString;
	}

private:
	char* str = nullptr;
	uint num_allocated = 0;
};

#endif // __STRING_H__
