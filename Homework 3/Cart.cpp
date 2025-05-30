//Julio Bonilla
//Student ID: 10026363
//Prog Logic
//HomeWorkAssignment 3
//May,Shane
//06-28-2017
//This application is used like a shopping cart
//to calculate subtotal from a read file, tax, and total due then
//to calcualte different tax ammounts according to category then
//ot calculate change due and write a receipt to a file

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const char kNewLine = '\n';//New line constant

const int kLineLength = 512;//Line length to ignore

const double kNTaxRate = 0.0825;// 8.25% Normal item tax rate

const double kXTaxRate = 0.125;// 12.5% Special item tax rate

const double kFTaxRate = 0.0;// 0.0% Food item tax rate

const int kStandardPrecision = 2;// Setting standard precision two decimal places

const int kSetWidthLeft = 37;// Setting width 37 spaces

const int kSetWidthRight = 5;// Setting width five spaces

int main()
{
	ifstream shoppingCart;//Declaring input stream
	shoppingCart.open("ItemList.txt");//Open Itemlist.txt

	ofstream receiptPrintOut;//Declaring output stream
	receiptPrintOut.open("Receipt.txt");//Writing to Receipt.txt
	receiptPrintOut << fixed << showpoint << setprecision(kStandardPrecision);
	receiptPrintOut << "Julio's Store" << endl;
	receiptPrintOut << kNewLine << endl;

	cout << "Opening File to read items..." << endl;


	double nSubtotal = 0.0;//Subtotal for Normal items declared
	double xSubtotal = 0.0;//Subtotal for Special items declared
	double fSubtotal = 0.0;//Subtotal for Food items declared
	int listCount = 0;//Item list counter declared
	while (!shoppingCart.eof())//While NOT end of file..
	{
		string itemName = "a";// item declared as "a" as soon as it is needed
		getline(shoppingCart, itemName);//The first item name is extracted

		double itemPrice = 0.0;//Item  price declaration
		shoppingCart >> itemPrice;//Item price extraction

		char itemCategory;//Item  category initailized
		shoppingCart >> itemCategory;//Item category extraction

		shoppingCart.ignore(kLineLength, kNewLine);//input stream to ignore 512th character and new line character
		receiptPrintOut << setw(kSetWidthLeft) << left << itemName << right << "$" << setw(kSetWidthRight) << itemPrice << " - " << itemCategory << endl;//Print to receipt in desired format

		if (itemCategory == 'N')
		{
			nSubtotal += itemPrice;//Adds N category total
		}
		else if (itemCategory == 'X')
		{
			xSubtotal += itemPrice;//Adds X category total
		}
		else if (itemCategory == 'F')
		{
			fSubtotal += itemPrice;//Adds F category total
		}

		listCount++;//Item list counter adds 1 each iteration
	}
	shoppingCart.close();

	cout << fixed << showpoint << setprecision(kStandardPrecision);

	double subtotal = 0.0;//Subtotal is declared to be used in calculation
	subtotal = nSubtotal + xSubtotal + fSubtotal;//Total of items is calculated
	cout << setw(kSetWidthLeft) << left << "Your Subtotal is ==>" << right << "$" << setw(kSetWidthRight) << subtotal << endl;//Subtotal is displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Subtotal" << right << "$" << setw(kSetWidthRight) << subtotal << endl;// Subtotal is printed

	double totalNTax = 0.0;//Tax for the N subtotal is declared
	double totalXTax = 0.0;//Tax for the X subtotal is declared
	double totalFTax = 0.0;//Tax for the F subtotal is declared
	totalNTax = nSubtotal * kNTaxRate;//N Tax to be added to the subtotal is calculated
	totalXTax = xSubtotal * kXTaxRate;//X Tax to be added to the subtotal is calculated
	totalFTax = fSubtotal * kFTaxRate;//F Tax to be added to the subtotal is calculated
	receiptPrintOut << setw(kSetWidthLeft) << left << "N Tax @ 8.25%" << right << "$" << setw(kSetWidthRight) << totalNTax << endl; //Tax rate to be printed
	receiptPrintOut << setw(kSetWidthLeft) << left << "X Tax @ 12.50%" << right << "$" << setw(kSetWidthRight) << totalXTax << endl; //Tax rate to be printed
	receiptPrintOut << setw(kSetWidthLeft) << left << "F Tax @ 0.00%" << right << "$" << setw(kSetWidthRight) << totalFTax << endl; //Tax rate to be printed

	double totalDue = 0.0;//Total amount due is declared
	totalDue = totalNTax + totalXTax + totalFTax + subtotal;//Total due is calculated
	cout << setw(kSetWidthLeft) << left << "Your Total amount due is ==>" << right << "$" << setw(kSetWidthRight) << totalDue << endl;//Total due is displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Total" << right << "$" << setw(kSetWidthRight) << totalDue << endl;//Total due to be printed
	cout << kNewLine << endl;

	double debitTendered = 0.0;//Tendered amount declared
	bool isValid = false;
	while (!isValid)
	{
		cout << setw(kSetWidthLeft) << left << "Please enter amount tendered ==>" << right << "$";//Amount tendered prompted
		cin >> debitTendered;//Tendered amount extracted

		if (debitTendered < totalDue || cin.fail())
		{
			cout << "ERROR! You've entered an invalid ammount! Ammount must be more than or equal to $" << totalDue << endl;//Invalid ammount prompt
			cin.clear();// invalid input is cleared from input stream
			cin.ignore(kLineLength, kNewLine);
			isValid = false;
		}
		else
		{
			isValid = true;
		}
	}

	receiptPrintOut << setw(kSetWidthLeft) << left << "Debit Tendered" << right << "$" << setw(kSetWidthRight) << debitTendered << endl;

	double changeDue = 0.0;//Change due declared
	changeDue = debitTendered - totalDue;//Change due calculated
	cout << setw(kSetWidthLeft) << left << "Your change is ==>" << right << "$" << setw(kSetWidthRight) << changeDue << endl;//Change due displayed
	receiptPrintOut << setw(kSetWidthLeft) << left << "Change Due" << right << "$" << setw(kSetWidthRight) << changeDue << endl;//Change due printed
	receiptPrintOut << "Number of items sold: " << listCount << endl;//Number of items sold printed
	receiptPrintOut << "Thank you for shopping @ Julio's Store!" << endl;
	receiptPrintOut.close();//Close file output stream
}