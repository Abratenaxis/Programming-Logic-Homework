// Julio Bonilla
//Prog Logic
// 07-5-2017
//HW 4
//This program is designed to:
//1-prompt user for a zip code
//2-convert int to a string
//3-convert string to an int


#include <iostream>
#include <string>

#include "ZipCodeUtil.h"

using namespace std;

using namespace zipcode_encoder_util;

int main()
{
	int zipCode = getUserPrompt("enter zipcode > ");
	
	bool validSize = isValidSize(zipCode);

	int zipCodeChecksumDigit = GenerateZipCodeChecksum(zipCode);


}