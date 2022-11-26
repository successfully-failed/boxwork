//Honestly i have no idea what that headder does, but i'll leave it for now



#ifndef ORYG_H
#define ORYG_H

#include <iostream>
#include <string>
#include <typeinfo>

//multictruct is a data structure that serves as universal variable
struct bigstruct
{
	int int_field; 
	char char_field;
	double double_field;
	bool bool_field;
	std::string string_field;
};

class MultiStruct
{
private:
	bigstruct structure;
public:
	MultiStruct();
	void getter(int a, char b, double c, bool d, std::string e)
	{
		structure.char_field = b;
		structure.int_field = a;
		structure.double_field = c;
		structure.bool_field = d;
		structure.string_field = e;
	}
};
		
		

		



class DoubleArray
{
		
};










































#endif 
