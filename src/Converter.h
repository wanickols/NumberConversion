#pragma once

enum ConversionTypes
	{
		Dec,
		Bin,
		Hex,
		Float,
		Null,
	};

class Converter
{
private:
	ConversionTypes inputType;
	std::string returnValue;
public:

	//Constructor
	Converter(const ConversionTypes& input_type);
	//Destructor+-
	~Converter();

	//Functions
	const std::string& convert(std::string& input, ConversionTypes returnType);




	//Conversions
	int binToDec(std::string val); //binary to decimal
	const std::string decToBin(int val); //decimal to binary

	int hexToDec(std::string val);//Hex to decimal
	const std::string decToHex(int val); //decimal to Hex

	const std::string hexToBin(std::string val);
	const std::string binToHex(std::string val);

	float binToFloat(std::string& val); // binary To Float;
	const std::string floatToBin(float& val); // float to binary;

	//Translations
	int translateHexToInt(const char letter);
	const std::string translateIntToHex(const int val);
	std::string translateHexToBinary(const char letter);

};
