#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>


#include "CreditCardUtil.h"

using namespace std;

namespace valid_creditcard_number_util
{

	long long GetCreditCardNumber(string prompt)
	{

		long long creditCardNumber = 0;
		cout << prompt;
		cin >> creditCardNumber;
		return creditCardNumber;
	}

	int GetSize(long long creditCardNumber)
	{
		long long workingNumber = creditCardNumber;
		int cardSize = 0;
		while (workingNumber)
		{
			workingNumber = workingNumber / kDecimalDividend;
			cardSize++;
		}
		return cardSize;
	}

	int GetPrefix(long long creditCardNumber, int prefixCount)
	{
		int prefix = 0;
		int numbersize = GetSize(creditCardNumber);
		prefix = creditCardNumber / pow(kDecimalDividend, (numbersize - prefixCount));

		return prefix;
	}

	string GetCardType(long long creditCardNumber)
	{
		string creditCardType = "a";

		if (GetPrefix(creditCardNumber, kSingleDigitPrefixCount) == kVisaPrefix)
		{
			creditCardType = "Visa";
		}
		else if (GetPrefix(creditCardNumber, kSingleDigitPrefixCount) == kMasterCardPrefix)
		{
			creditCardType = "Master Card";
		}
		else if (GetPrefix(creditCardNumber, kSingleDigitPrefixCount) == kDiscoverCardPrefix)
		{
			creditCardType = "Discover Card";
		}
		else if (GetPrefix(creditCardNumber, kDoubleDigitPrefixCount) == kAmericanExpPrefix)
		{
			creditCardType = "American Express";
		}
		else
		{
			creditCardType = "Not a valid Card Type";
		}
		return creditCardType;
	}

	int GetDigit(int tDigit)
	{
		int digitSize = GetSize(tDigit);
		if (digitSize > 1)
		{
			int sum = 0;
			int counter = digitSize;
			while (counter != 0)
			{
				int digit = tDigit % kDecimalDividend;
				sum += digit;
				counter--;
				tDigit /= 10;
			}
			return sum;
		}
		else
		{
			return tDigit;
		}
	}

	int SumOfDoubleEvenPlace(long long creditCardNumber)
	{
		long long workingCopy = creditCardNumber;
		int sum = 0;
		int digitCount = 1;
		while (workingCopy != 0)
		{
			int digit = workingCopy % kDecimalDividend;
			int tDigit = GetDigit(digit);
			if (digitCount % 2 == 0)
			{
				sum += 2 * tDigit;
			}
			digitCount++;
			workingCopy /= kDecimalDividend;
		}
		return sum;
	}

	int SumOfOddPlace(long long creditCardNumber)
	{
		long long workingCopy = creditCardNumber;
		int sum = 0;
		int digitCount = 1;
		while (workingCopy != 0)
		{
			int digit = workingCopy % kDecimalDividend;
			if (digitCount % 2 != 0)
			{
				sum += digit;
			}
			digitCount++;
			workingCopy /= kDecimalDividend;
		}
		return sum;
	}
}

