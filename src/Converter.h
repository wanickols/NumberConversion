enum ConversionTypes
{
	Dec,
	Bin,
	Hex,
	Float,
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

	template<typename T>
	
	inline T stringToVal(std::string input)
	{
		std::size_t pos{};
		try {
			T val;
			if (inputType == ConversionTypes::Float)
				 val = stof(input);
			else
				 val = stoi(input);
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

	}
	

	//Conversions
	int binToDec(std::string & val); //binary to decimal
	const std::string decToBin(int val); //decimal to binary

	int hexToDec(std::string val);//Hex to decimal
	const std::string decToHex(int val); //decimal to Hex

	const std::string hexToBin(std::string val);
	const std::string binToHex(const int& val);

	float binToFloat(const int& val); // binToFloat;
	int floatToDec(const float& val); // binToFloat;

	//Translations
	int translateHexToInt(const char letter);
	const std::string translateIntToHex(const int val);
	
	std::string translateHexToBinary(const char letter);

};

