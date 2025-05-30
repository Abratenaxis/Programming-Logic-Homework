//Julio Bonilla
//Student ID: 10026363
//Prog Logic
//HomeWorkAssignment 1
//May,Shane
//06-13-2017
//This application is used like a shopping cart
//to calculate subtotal, tax, and total due then
//to calcualte change due

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int kLineLength = 512;

const double kTaxRate = 0.0825;

int main()
{
	cout << "Please enter your first item's description ==> ";//Prompted for first item
	string itemOneName = " ";//First item declared as " " as soon as it is needed
	getline(cin, itemOneName);//The first item name is extracted

	cout << "Please enter " << itemOneName << "'s price ==> $";//Item one price prompt
	double itemOnePrice = 0.0;//Item one price declaration
	cin >> itemOnePrice;//Item one price extraction

	cout << "Please enter category (F, N, or X) for " << itemOneName << " ==> ";//Item one category prompt
	char itemOneCategory;//Item one category initailized
	cin >> itemOneCategory;//Item one category extraction

	cin.ignore(kLineLength, '\n');//input stream to ignore 512th character and new line character
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Please enter your second item's description ==> ";
	string itemTwoName = " ";
	getline(cin, itemTwoName);

	cout << "Please enter " << itemTwoName << "'s price ==> $";
	double itemTwoPrice = 0.0;
	cin >> itemTwoPrice;

	cout << "Please enter category (F, N, or X) for " << itemTwoName << " ==> ";
	char itemTwoCategory;
	cin >> itemTwoCategory;

	cin.ignore(kLineLength, '\n');
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Please enter your last item's description ==> ";
	string itemThreeName = " ";
	getline(cin, itemThreeName);

	cout << "Please enter " << itemThreeName << "'s price ==> $";
	double itemThreePrice = 0.0;
	cin >> itemThreePrice;

	cout << "Please enter category (F, N, or X) for " << itemThreeName << " ==> ";
	char itemThreeCategory;
	cin >> itemThreeCategory;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << fixed << showpoint;

	double subtotal = 0.0;//Subtotal is declared to be used in calculation
	subtotal = itemOnePrice + itemTwoPrice + itemThreePrice;//Total of items is calculated
	cout << "Your Subtotal is ==> $" << subtotal <<endl;//Subtotal is displayed
	cout << "The current Tax Rate is 8.25%" << endl;//Tax Rate is displayed
	double totalTax = 0.0;//Tax for the subtotal is declared
	totalTax = subtotal * kTaxRate;//Tax to be added to the subtotal is calculated

	double totalDue = 0.0;//Total amount due is declared
	totalDue = totalTax + subtotal;//Total due is calculated
	cout << "Your Total amount due is ==> $" << totalDue << endl;//Total due is displayed

	cout << "Please enter amount tendered ==> $";//Amount tendered prompted
	double debitTendered = 0.0;//Tendered amount declared
	cin >> debitTendered;//Tendered amount extracted

	double changeDue = 0.0;//Change due declared
	changeDue = debitTendered - totalDue;//Change due calculated
	cout << "Your change is ==> $" << changeDue << endl;//Change due displayed

}