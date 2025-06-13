// Julio Bonilla
//Prog Logic
// 07-5-2017
//HW 4
//This program is designed to:
//1-prompt user for a zip code
//2-convert int to a string
//3-convert string to an int

#ifndef ZIPENCODER_H
#define ZIPENCODER_H

#include <iostream>
#include <string>

using namespace std;

namespace zipcode_encoder_util
{
	const int kZipCodeIntLength = 5;

	int getUserPrompt(string);

	bool isValidSize(int);

	int GenerateZipCodeChecksum(int);

	string generateBarcode(int);

	string GetEncoding(int);

	void OutputToUser(string);

	string zipEncoder(string, int);

	string setBarCode(string, int);

	//void setBarCode(int);

	int getZipCode();

	string getBarCode();

	bool isValidBar(string);

	string zipCodeToBarCode(int);

	int barCodeToZipCode(string);



	string barcode;
}

#endif // !ZIPENCODER_H