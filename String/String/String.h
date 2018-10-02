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
	bool is_empty() {
		return num_allocated == 0;
	}
	
	void clear() {
		delete str;
		str = nullptr;
		num_allocated = 0;
	}	
	
	//Operators
	void operator=(String &string) {
		str = string.str;
	}

	void operator+=(String &string) {
		
	}

	bool operator==(String &string) const {
		return (str == string.str);
	}

private:
	char* str = nullptr;
	uint num_allocated = 0;

};

#endif // __STRING_H__
