#ifndef __STRING_H__
#define __STRING_H__

#include <cstring>

typedef unsigned int uint;

class String {

public:
	//Constructors
	String() {}

	String(const char* string) : 
		mem_allocated(strlen(string) + 1),

		str(new char[mem_allocated])
	{
		strcpy_s(str, mem_allocated, string);
	}

	String(const String &string) :
		mem_allocated(string.mem_allocated + 1),
		str(new char[mem_allocated])
	{
		strcpy_s(str, mem_allocated, string.str);
	}
	
	//Destructor
	~String() {
		clear();
	}

	//Methods
	bool is_empty() {
		return mem_allocated == 0;
	}
	
	void clear() {
		if (str != nullptr) {
			delete[] str;
			str = nullptr;
			mem_allocated = 0;
		}
	}	

	uint length() {
		if (str != nullptr)
			return strlen(str);
	}
	
	//Operators
	void operator+=(String &string) {
		uint newAllocated = mem_allocated + strlen(string.str) + 1;
		char* newString = new char[newAllocated];
		strcpy(newString, str);
		strcat(newString, string.str);
		clear();
		mem_allocated = newAllocated;
		str = newString;
	}

	void operator=(String &string) {
		clear();
		mem_allocated = strlen(string.str);
		str = string.str;
	}

	bool operator==(String &string) const {
		return (str == string.str);
	}

	String operator+(String &string) const {
		String newString(str);
		newString += string;
		return newString;
	}

private:
	char* str = nullptr;
	uint mem_allocated = 0;
};

#endif // __STRING_H__
