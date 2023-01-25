#include "pch.h"
#include "Converter.h"

using namespace std;

int main() 
{
	//Input Type
	ConversionTypes inputType = ConversionTypes::Float;

	Converter conv = Converter(inputType);

	//Dec to binary and back test
	int intPut{ 53};
	string input = conv.decToBin(intPut);

	cout << input << endl;
	cout << conv.binToDec(input) << endl;


	//Dec to hex and back test
	int dhInput = 1234;

	string hdInput = conv.decToHex(intPut);
	cout << hdInput << endl;
	cout << conv.hexToDec(hdInput) << endl;


	cout << conv.hexToBin(hdInput);
	//cout << conv.convert(input, ConversionTypes::Dec);


	return 0;
}



