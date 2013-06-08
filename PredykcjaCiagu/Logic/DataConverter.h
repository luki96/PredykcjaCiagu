#pragma once
#include <vector>

class DataConverter
{
private:

	/** Wspolczynnik mowiacy przez "ile" beda dzielone dane odczytane z pliku */
	const int DIVISIOR;

	/** Tablica zawierajaca dane skonwertowane do przedzialu (0;1> */
	std::vector<double> convertedData;

public:
	/** Konstruktor klasy DataConverter */
	DataConverter(void);
	
	/** Destruktor klasy DataConverter */
	~DataConverter(void);

	/** Metoda konwertuje dane do przedzialu funkcji sigmoidalnej czyli (0;1> 
	@param std::vector<int> data Tablica z danymi, ktore maja zostac przeskalowane
	*/
	void ConvertDataToSigmoidFunctionRange(std::vector<int> data);

	/** Getter dla pola convertedData
	@return tablica zawierajaca dane skonwertowane do przedzialu funkcji sigmoidalnej
	*/
	std::vector<double> GetConvertedData()
	{
		return convertedData;
	}
};

