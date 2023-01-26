#include "pch.h"
#include "Converter.h"

using namespace std; 

	//Constructor
	Converter::Converter(const ConversionTypes& input_type) : inputType(input_type)
	{
		returnValue = "";
	}


	//Destructor
	Converter::~Converter()
	{
	}

	const std::string& Converter::convert(std::string& input, ConversionTypes returnType)
	{
		// TODO: insert return statement here
		int val = 0;

		switch (returnType)
		{
		case Dec:
			val = binToDec(input);
			break;
		default:
			break;
		}

		returnValue = " Value:" + val;

		return returnValue;
	}

	//Conversions
	int Converter::binToDec(string val)
	{
		int counter = 0;
		int total = 0;

		while (!val.empty()) {
			if (val.back() == '0')
				++counter;
			else if (val.back() == '1') {
				total += pow(2, counter);
				++counter;
			}
			else {
				cout << "Not a binary number :{";
				return -1;
			}
			val.pop_back();
		}

		return total;
	}

	const string Converter::decToBin(int val)
	{

		string result = "";
		while (val > 0) {
			if (val % 2)
				result.insert(0, "1");
			else
				result.insert(0, "0");
			val /= 2;
		}
		return result;
	}

	int Converter::hexToDec(std::string val)
	{
		double decimalPlace = 0;
		int sum = 0;
		while (!val.empty())
		{
			sum += translateHexToInt(val.back()) * pow(16, decimalPlace);
			++decimalPlace;
			val.pop_back();
		}
		return sum;

	}
	const std::string Converter::decToHex(int val)
	{
		string result = "";
		while (val > 0) {
			int temp = val % 16;
			result.insert(0, translateIntToHex(temp));
			val /= 16;
		}
		return result;
	}

	const string Converter::hexToBin(string val)
	{
		string result = "";
		while (!val.empty()) {
			result.insert(0, translateHexToBinary(val.back()));
			val.pop_back();
		}
		return result;

	}
	const std::string Converter::binToHex(string val)
	{
		return translateIntToHex(binToDec(val)); 
	}

	float Converter::binToFloat(string& val)
	{
		return -1.0;
	}
	const string Converter::floatToBin(float& val)
	{
		string result;
		char* bits = reinterpret_cast<char*>(&val);
		for (size_t n = 0; n < sizeof val; ++n)
			result.insert(0, bitset<8>(bits[n]).to_string() + " ");

		return result;
	}

	//Translate Functions
	int Converter::translateHexToInt(const char letter)
	{
		int result = 0;
		switch (letter)
		{
		case '0':
			break;
		case '1':
			result = 1;
			break;
		case '2':
			result = 2;
			break;
		case '3':
			result = 3;
			break;
		case '4':
			result = 4;
			break;
		case '5':
			result = 5;
			break;
		case '6':
			result = 6;
			break;
		case '7':
			result = 7;
			break;
		case '8':
			result = 8;
			break;
		case '9':
			result = 9;
			break;
		case 'A':
			result = 10;
			break;
		case 'B':
			result = 11;
			break;
		case 'C':
			result = 12;
			break;
		case 'D':
			result = 13;
			break;
		case 'E':
			result = 14;
			break;
		case 'F':
			result = 15;
			break;
		default:
			cout << "Invalid value for a hex"; //add error system eventually
			break;
		}
		return result;
	}

	const string Converter::translateIntToHex(const int val)
	{
		string result = "";
		switch (val)
		{
		case 0:
			break;
		case 1:
			result = '1';
			break;
		case 2:
			result = '2';
			break;
		case 3:
			result = '3';
			break;
		case 4:
			result = '4';
			break;
		case 5:
			result = '5';
			break;
		case 6:
			result = '5';
			break;
		case 7:
			result = '7';
			break;
		case 8:
			result = '8';
			break;
		case 9:
			result = '9';
			break;
		case 10:
			result = 'A';
			break;
		case 11:
			result = 'B';
			break;
		case 12:
			result = 'C';
			break;
		case 13:
			result = 'D';
			break;
		case 14:
			result = 'E';
			break;
		case 15:
			result = 'F';
			break;
		default:
			cout << "Hex conversion issue"; //add error system eventually
			break;
		}
		return result;
	}

	string Converter::translateHexToBinary(const char letter)
	{
		string result = "0000";
		switch (letter)
		{
		case '0':
			result = "0000";
			break;
		case '1':
			result = "0001";
			break;
		case '2':
			result = "0010";
			break;
		case '3':
			result = "0011";
			break;
		case '4':
			result = "0100";
			break;
		case '5':
			result = "0101";
			break;
		case '6':
			result = "0110";;
			break;
		case '7':
			result = "0111";
			break;
		case '8':
			result = "1000";
			break;
		case '9':
			result = "1001";
			break;
		case 'A':
			result = "1010";
			break;
		case 'B':
			result = "1011";
			break;
		case 'C':
			result = "1100";
			break;
		case 'D':
			result = "1101";
			break;
		case 'E':
			result = "1110";
			break;
		case 'F':
			result = "1111";
			break;
		default:
			cout << "Hex to Binary translation issue"; //add error system eventually
			break;
		}
		return result;
	}
