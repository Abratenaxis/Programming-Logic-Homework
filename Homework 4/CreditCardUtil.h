#ifndef VALIDNUMBERUTIL_H
#define VALIDNUMBERUTIL_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

namespace valid_creditcard_number_util
{
    const int kPrefixDividend = 2;

    const int kDecimalDividend = 10;

    const int kVisaPrefix = 4;

    const int kMasterCardPrefix = 5;

    const int kAmericanExpPrefix = 37;

    const int kDiscoverCardPrefix = 6;

    const int kSingleDigitPrefixCount = 1;

    const int kDoubleDigitPrefixCount = 2;

    /**
    * The minimum size of a credit card (13 integers).
    */
    const long long kMinCreditCardSize = 1000000000000;

    /**
    * The maximum size of a credit card (16 integers).
    */
    const long long kMaxCreditCardSize = 9999999999999999;

    /**
    *
    */
    const int kLineLength = 512;

    /**
    *
    */
    const char kNewLine = '\n';

    /**
    *
    */
    long long GetCreditCardNumber(string);

    /**
    *
    */
    int GetSize(long long);

    /**
    *
    */
    int GetPrefix(long long, int);

    /**
    *
    */
    string GetCardType(long long);

    /**
    *
    */
    int GetDigit(int);

    /**
    *
    */
    int SumOfDoubleEvenPlace(long long);

    /**
    *
    */
    int SumOfOddPlace(long long);

    /**
    *
    */
    bool IsPrefixMatched(long long, int);

    /**
    *
    */
    bool IsValid(long long);

}

#endif