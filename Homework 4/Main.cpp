// Julio Bonilla
//Prog Logic
// 07-5-2017
//HW 4
//This program is designed to:
//1-prompt user for card number
//2-get the size of number
//3-get the prefix of the number and validate that it is a valid type
//4-get the digit of a number greater than 9
//5 get the sum of odd and even places
// did the best I could


#include <iomanip>
#include <iostream>
#include <string>

#include "CreditCardUtil.h"

using namespace std;

using namespace valid_creditcard_number_util;

int main()
{

    long long creditCardNumber = GetCreditCardNumber("Enter a Credit Card number > ");
    cout << creditCardNumber << endl;

    // int cardSize = GetSize(183756490859876);
    // cout << cardSize << endl;
    //
    // int prefix = GetPrefix(123456789123, 2);
    // cout << prefix << endl;
    //
    // string cardType = GetCardType(9123456789123);
    // cout << cardType << endl;
    //
    // int targetDigit = GetDigit(18);
    // cout << targetDigit << endl;
    //
    //  int cardSumEven = SumOfDoubleEvenPlace(4388576018402626);
    //  cout << cardSumEven << endl;
    //
    // int cardSumOdd = SumOfOddPlace(4388576018402626);
    // cout << cardSumOdd << endl;
}

