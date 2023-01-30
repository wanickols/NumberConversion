#pragma
#include "Converter.h"

class TextHandler 
{
private:
	ConversionTypes inputType;
	ConversionTypes convertType;
	std::string inputValue;
public:
	TextHandler();
	~TextHandler();

	const bool conversionDialog(); // runs conversion program
	const bool test(); //runs through all test cases
private:
	bool conversionTest();
	const ConversionTypes getConvertType(std::string& val);
	
	

};