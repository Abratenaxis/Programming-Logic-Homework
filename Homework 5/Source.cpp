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

namespace zipcode_encoder_util
{



	// *** prompts user for input ***
	// *** @return input ***
	int getUserPrompt(string outputPromt)
	{
		int input = 0;
		cout << outputPromt << endl;
		cin >> input;
		return input;
	}

	void OutputToUser(string outputString)
	{
		cout << "|";
		cout << outputString;
		cout << "|" << endl;
	}

	// *** validate number size ***
	// *** return true if size is greater than 4 digits and less than 6 digits
	bool isValidSize(int numberToValidate)
	{
		// *** is valid number ***
		if (9999 < numberToValidate < 100000)
		{
			return true;
		}
		// *** is invalid number ***
		else return false;
	}

	// *** Calculate and Return ZipCode Checksum Digit ***
	int GenerateZipCodeChecksum(int zipcode)
	{

		int sum = 0;
		int digitCount = 1;
		while (zipcode != 0)
		{
			int digit = zipcode % 10;
			if (digitCount != 0)
			{
				sum += digit;
			}
			digitCount++;
			zipcode /= 10;
		}

		int counter = 0;
		// *** While Not Divisible By 10 ***
		while (!(sum % 10 == 0))
		{
			// *** Increment checksum digit until sum is divisible by 10 ***
			counter++;
			// *** add to check ***
			sum += counter;
			if (sum % 10 == 0) {
				break;
			}
		}
		// *** Return Checksum Digit ***
		return counter;

	}

	// *** Returns String Encoded Barcode ***
	// *** Could Be Malformed Due To Invalid Input ***
	string generateBarcode(int zipcode, int checksum)
	{
		string barcode = "";
		while (zipcode != 0)
		{
			int digit = zipcode % 10;
			string encodedDigit = GetEncoding(digit);
			if (encodedDigit != "invalid-digit")
			{
				barcode += encodedDigit;
			}
			zipcode /= 10;
		}
		string encodedchecksum = GetEncoding(checksum);
		barcode += encodedchecksum;
		return barcode;
	}

	//int DecodeBarcode(string barcode)
	//{
	//	int barcodeLength = barcode.length();
	//	if (barcodeLength != 0)
	//	{
	//		string cleanBarcode = "";
	//		for (int i = 0; i < barcodeLength; i++)
	//		{
	//			
	//			if (i == 0) {
	//				cleanBarcode = barcode.substr(1, barcodeLength-1);
	//				string digitSection = cleanBarcode.substr(25);
	//			}

	//			}

	//		}

	//	}

	//}

	string GetEncoding(int digitToEncode)
	{
		string zipEncoder[10] = { ":::||", "::|:|", "::||:", ":|::|", ":|:|:", ":||::", "|:::|", "|::|:", "|:|::", "||:::" };
		switch (digitToEncode)
		{
		case 0:
			return zipEncoder[9];
		case 1:
			return zipEncoder[0];
		case 2:
			return zipEncoder[1];
		case 3:
			return zipEncoder[2];
		case 4:
			return zipEncoder[3];
		case 5:
			return zipEncoder[4];
		case 6:
			return zipEncoder[5];
		case 7:
			return zipEncoder[6];
		case 8:
			return zipEncoder[7];
		case 9:
			return zipEncoder[8];
		default:
			return "invalid-digit";
		}
	}


}