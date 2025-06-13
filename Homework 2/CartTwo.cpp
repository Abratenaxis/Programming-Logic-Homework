//Julio Bonilla
//Student ID: 10026363
//Prog Logic
//HomeWorkAssignment 2
//May,Shane
//06-21-2017
//This application is used like a shopping cart
//to calculate subtotal from a read file, tax, and total due then
//to calcualte change due and write a receipt to a file

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int kLineLength = 512;

const double kTaxRate = 0.09;

const int kStandardPrecision = 2;

const int kSetWidthLeft = 37;

const int kSetWidthRight = 5;

int main()
{
	ifstream shoppingCart;
	shoppingCart.open("../Items.txt");

	cout << "Opening File to read items..." << endl;
	string itemOneName = " ";//First item declared as " " as soon as it is needed
	getline(shoppingCart, itemOneName);//The first item name is extracted

	double itemOnePrice = 0.0;//Item one price declaration
	shoppingCart >> itemOnePrice;//Item one price extraction

	char itemOneCategory;//Item one category initailized
	shoppingCart >> itemOneCategory;//Item one category extraction

	shoppingCart.ignore(kLineLength, '\n');//input stream to ignore 512th character and new line character
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	string itemTwoName = " ";
	getline(shoppingCart, itemTwoName);

	double itemTwoPrice = 0.0;
	shoppingCart >> itemTwoPrice;

	char itemTwoCategory;
	shoppingCart >> itemTwoCategory;

	shoppingCart.ignore(kLineLength, '\n');
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	string itemThreeName = " ";
	getline(shoppingCart, itemThreeName);

	double itemThreePrice = 0.0;
	shoppingCart >> itemThreePrice;

	char itemThreeCategory;
	shoppingCart >> itemThreeCategory;
	shoppingCart.close();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ofstream receiptPrintOut;
	receiptPrintOut.open("../Receipt.txt");
	receiptPrintOut << fixed << showpoint << setprecision(kStandardPrecision);

	receiptPrintOut << "Julio's Store" << endl;
	receiptPrintOut << "\n" << endl;
	receiptPrintOut << setw(kSetWidthLeft) << left << itemOneName <<  right << "$" << setw(kSetWidthRight) << itemOnePrice << " - " << itemOneCategory << endl;
	receiptPrintOut << setw(kSetWidthLeft) << left << itemTwoName  << right << "$" << setw(kSetWidthRight) << itemTwoPrice << " - " << itemTwoCategory << endl;
	receiptPrintOut << setw(kSetWidthLeft) << left << itemThreeName  << right << "$" << setw(kSetWidthRight) << itemThreePrice << " - " << itemThreeCategory << endl;

	cout << fixed << showpoint << setprecision(kStandardPrecision);

	double subtotal = 0.0;//Subtotal is declared to be used in calculation
	subtotal = itemOnePrice + itemTwoPrice + itemThreePrice;//Total of items is calculated
	cout << setw(kSetWidthLeft) << left << "Your Subtotal is ==>"  << right << "$" << setw(kSetWidthRight) << subtotal << endl;//Subtotal is displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Subtotal"  << right << "$" << setw(kSetWidthRight) << subtotal << endl;
	cout << "The current Tax Rate is 9%" << endl;//Tax Rate is displayed
	double totalTax = 0.0;//Tax for the subtotal is declared
	totalTax = subtotal * kTaxRate;//Tax to be added to the subtotal is calculated
	receiptPrintOut << setw(kSetWidthLeft) << left << "Tax @ 9%" << right << "$" << setw(kSetWidthRight) << totalTax << endl; //Tax rate to be printed

	double totalDue = 0.0;//Total amount due is declared
	totalDue = totalTax + subtotal;//Total due is calculated
	cout << setw(kSetWidthLeft) << left << "Your Total amount due is ==>" << right << "$" << setw(kSetWidthRight) << totalDue << endl;//Total due is displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Total"  << right << "$" << setw(kSetWidthRight) << totalDue << endl;

	cout << "\n" << endl;
	cout << setw(kSetWidthLeft) << left << "Please enter amount tendered ==>" << right << "$";//Amount tendered prompted
	double debitTendered = 0.0;//Tendered amount declared
	cin >> debitTendered;//Tendered amount extracted
	receiptPrintOut << setw(kSetWidthLeft) << left << "Debit Tendered" << right << "$" << setw(kSetWidthRight) << debitTendered << endl;

	double changeDue = 0.0;//Change due declared
	changeDue = debitTendered - totalDue;//Change due calculated
	cout << setw(kSetWidthLeft) << left << "Your change is ==>" << right << "$" << setw(kSetWidthRight) << changeDue << endl;//Change due displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Change Due"  << right << "$" << setw(kSetWidthRight) << changeDue << endl;
	receiptPrintOut << "Number of items sold: 3" << endl;
	receiptPrintOut << "Thank you for shopping @ Julio's Store!" << endl;
}
