#include "pch.h"
#include "TextHandler.h"
#include "Converter.h"

using namespace std;

TextHandler::TextHandler()
{
}

TextHandler::~TextHandler()
{
}

void TextHandler::conversionDialog()
{
	string response;
	
	//Intro dialog
	cout << "Hello and welcome to my conversion progam. Going to be converting are we? \n"
		<< "What number type are you going to start with ";

	inputType = getConvertType(response);
		
	cout << "Great! please enter the value you'd like to convert. " << endl;

	getline(cin, response);


	float f;
	int i;
	if (inputType == Dec)
	{
		if (response.find('.')) {
			inputType = Float;
		
			f = stringToVal<float>(response);

		
		}else
			i = stringToVal<int>(response);

	}
	
	cout << "Nice number! " << endl;

	cout << "One last question. What are we converting to " << endl;

	convertType = getConvertType(response);

	cout << "Amazing! time to do some converting ..." << endl;

	for (int i = 0; i < 3; i++) {
		cout << "..." << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

}

const ConversionTypes TextHandler::getConvertType(string& val)
{

	cout << "(DEC, BIN, HEX)?" << endl;

	ConversionTypes type = Null;
	
	while (type == Null) {
		
		getline(cin, val);
		
		if (val == "DEC")
			type = Dec;
		else if (val == "BIN")
			type = Bin;
		else if (val == "HEX")
			type = Hex;
		
		if(type == Null)
			cout << "Oh no, that wasn't a type. Please enter 'DEC' , 'BIN' , or 'HEX'. " << endl;
	}
	return type;
}

bool TextHandler::test()
{
	bool results = true;

	if (!conversionTest())
		results = false;

	return results;
}

bool TextHandler::conversionTest()
{
	//Input Type
	ConversionTypes inputType = ConversionTypes::Float;

	Converter conv = Converter(inputType);

	//Dec to binary and back test
	int intPut{ 6 };
	string input = conv.decToBin(intPut);


	cout << input << endl;
	cout << conv.binToDec(input) << endl;


	//Dec to hex and back test
	int dhInput = 1234;

	string hdInput = conv.decToHex(intPut);
	cout << hdInput << endl;
	cout << conv.hexToDec(hdInput) << endl;


	string bhInput = conv.hexToBin(hdInput);
	cout << bhInput << endl;
	cout << conv.binToHex(bhInput) << endl;
	//cout << conv.convert(input, ConversionTypes::Dec);

	float fbInput = -6.0;

	//Floats
	string bfInput = conv.floatToBin(fbInput);
	cout << bfInput << endl;
	cout << conv.binToFloat(bfInput);

    return true;
}
