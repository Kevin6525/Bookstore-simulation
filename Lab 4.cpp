// Kevin Lee
// Kevin6523@gmail.com
// Lab #4
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
// Defining profit rate as a global constant
#define PROFIT 0.8
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Prototype
int numBooks(int numCopies, char req, char newOld);
double calcProfit(int numBooks, double price);
void output(string isbn, int copies, double profit);

int main() {
	//Variable declarations
	string bookNumber;
	int numClass, totalBook;
	double price, profit;
	char reqSug, newOld;
	//Prompting user for input and assigning input to variables
	cout<<"Enter book number: ";
	getline(cin,bookNumber);
	cout<<"Enter price per copy: ";
	cin>>price;
	cout<<"Enter expected class enrollment: ";
	cin>>numClass;
	cout<<"Enter 'R' if required or 'S' if suggested: ";
	cin>>reqSug;
	cout<<"Enter 'N' if new or 'O' if not a new text: ";
	cin>>newOld;
	//Calling other functions to calculate profit and number of copies needed
	totalBook = numBooks(numClass, reqSug, newOld);
	profit = calcProfit(totalBook, price);
	//This case is to catch if someone doesn't enter the correct character for the last two prompts
	if(totalBook == -1)
	{
		cout<<endl;
		cout<<"Error, please restart the program and re-enter your info."<<endl;
		cout<<"Kevin Lee"<<endl<<"Kevin6523@gmail.com"<<endl<<"Lab #4";
		return 0;
	}
	//Call function to output
	output(bookNumber, totalBook, profit);
	return 0;
}
int numBooks(int numCopies, char req, char newOld)
{
	//Pre: numCopies - Total copies needed
	// req - character indicating required or suggested
	//newOld - character indicating new or old
	//Post: number of books sold as calculated in the return statement
	//Purpose - Calculate total books sold
	//We use if statements and conditionals to calculate the number of books needed
	if(toupper(req) == 'R')
	{
		if(toupper(newOld) == 'O')
		{
			return(numCopies * 0.65 + 0.5);
		}
		else
		{
			return(numCopies * 0.9 + 0.5);
		}
	}
	//First loop deals with all required texts old or new
	else if(toupper(req) == 'S')
	{
		if(toupper(newOld) == 'O')
		{
			return(numCopies * 0.2 + 0.5);
		}
		else
		{
			return(numCopies * .4 + 0.5);
		}
	}
	//Second loop deals with all suggested texts old or new
	else
	{
		return -1;
	}
	//This loop deals with any mistakes or mistyped inputs.
	//Note: We add 0.5 to all end values to round to the nearest whole number as the program would truncate the values without it
}
double calcProfit(int numBooks, double price)
{
	//Pre: numBooks - Total number of books sold
	//price - price per book
	//Post: Total profit (equation in return statement)
	//Purpose - Calcualte total profits given book price, number of copies sold and the margin of profit 
	//Returns the profits from selling the number of books
	return((numBooks * price)*(1-PROFIT));
}
void output(string isbn, int copies, double profit)
{
	//Pre: isbn - Book ID
	//copies - number of copies needed
	//profit - total profit made from book sales
	//Post: none
	//Purpose: Print out results
	//Formatting the output with a blank line first
	cout<<endl;
	cout<<"ISBN: "<<isbn<<endl;
	cout<<"Copies Needed: "<<copies<<endl;
	//We use the setprecision to ensure that we only print out to 2 decimal places
	cout<<"Profit: $"<<fixed<<setprecision(2)<<profit<<endl;
}
//Output Case 1:
//Enter book number: 0755798652
//Enter price per copy: 34.98
//Enter expected class enrollment: 35
//Enter 'R' if required or 'S' if suggested: R
//Enter 'N' if new or 'O' if not a new text: O
//
//ISBN: 0755798652
//Copies Needed: 23
//Profit: $160.91
//Kevin Lee
//Kevin6523@gmail.com
//Lab #4

//Output Case 2:
//Enter book number: 0755798652
//Enter price per copy: 34.98
//Enter expected class enrollment: 34
//Enter 'R' if required or 'S' if suggested: R
//Enter 'N' if new or 'O' if not a new text: O
//
//ISBN: 0755798652
//Copies Needed: 22
//Profit: $153.91
//Kevin Lee
//Kevin6523@gmail.com
//Lab #4

//Output Case 3:
//Enter book number: 2462462464
//Enter price per copy: 5.95
//Enter expected class enrollment: 40
//Enter 'R' if required or 'S' if suggested: S
//Enter 'N' if new or 'O' if not a new text: O
//
//ISBN: 2462462464
//Copies Needed: 8
//Profit: $9.52
//Kevin Lee
//Kevin6523@gmail.com
//Lab #4

//Output Case 4:
//Enter book number: 8953647888
//Enter price per copy: 65.99
//Enter expected class enrollment: 35
//Enter 'R' if required or 'S' if suggested: N
//Enter 'N' if new or 'O' if not a new text: Y
//
//Error, please restart the program and re-enter your info.
//Kevin Lee
//Kevin6523@gmail.com
//Lab #4
