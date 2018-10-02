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
		str(new char[num_allocated])
	{
		strcpy(str, string);
	}

	String(const String &string) : 
		num_allocated(string.num_allocated),
		str(new char[num_allocated])
	{
		strcpy(str, string.str);
	}
	
	//Destructor
	~String() {
		clear();
	}

	//Methods
	void clear() {

	}

private:
	char* str = nullptr;
	uint num_allocated = 0;

};

#endif // __STRING_H__
