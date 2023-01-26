#pragma
#include "Converter.h"

class TextHandler 
{
private:
	ConversionTypes inputType;
	ConversionTypes convertType;
public:
	TextHandler();
	~TextHandler();

	void conversionDialog(); // runs conversion program
	bool test(); //runs through all test cases
private:
	bool conversionTest();
	const ConversionTypes getConvertType(std::string& val);
	template<typename T>
	inline T stringToVal(std::string input)
	{


		std::size_t pos{};


		try {
			//Floats
			T val;

			if (inputType == ConversionTypes::Dec) 
			val = stoi(input);
			else
			val = stof(input);

			return val;
		}
		catch (std::invalid_argument const& ex)
		{
			std::cout << "Invalid Argumnet. " << ex.what() << " Is not a number :{" << '\n';
			return -1;
		}
		catch (std::out_of_range const& ex)
		{
			std::cout << "Out of range. " << '\n';
			const long long ll{ std::stoll(input, &pos) };
			std::cout << "std::stoll('" << input << "'): " << ll << "; pos: " << pos << '\n';
			std::cout << "You think we're made of memory here?";
			return -1;
		}


	}//runs through all conversion related test

};