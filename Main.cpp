// This program adds two large integers, and prints the result to the screen
 /*
	Philip Teague
	Saul Sven Reyes
	Nathaniel Ramirez
	Talal Elhitu
	Wesley Matusik
	Kenneth Rouse
 */

#include <cctype>
#include <iostream>
using namespace std;

// Max number of digits in the large integer
const int MAXSIZE = 25;

// Initializes an integer array so that all positions are holding the value zero.
void initArray(int array[]);

// Gets a large integer from the keyboard and stores each individual digit
// into the array.
void getNum(int array[]);

// Prints a large integer to the screen. Leading zeros are not printed.
void printNum(int array[]);

// Adds up the 2 large numbers and checks for an overflow error
void addition(int arraySum[], int array1[], int array2[]);

int main()
{
	// TODO: Write code for the main function
	int arraySum[MAXSIZE];
	int array1[MAXSIZE];
	int array2[MAXSIZE];

	// Initializes the 2 arrays so the starting values are 0
	initArray(array1);
	initArray(array2);

	// Gets the numbers from the user input and converts to int data type
	getNum(array1);
	getNum(array2);

	// Adds up the 2 numbers and checks for an overflow error
	addition(arraySum, array1, array2);

	// Displays the result to the user
	printNum(arraySum);

	cout << endl;
	return 0;
}

void initArray(int array[])
{
	// TODO: Write code for the function

	// Sets all the elements in the array to 0
	for (int i = 0; i < MAXSIZE; i++)
	{
		array[i] = 0;
	}
}


void printNum(int array[])
{
	// TODO: Write code for the function

	// Declares start variable
	int start = 0;

	// This gets the starting position of the number instead of starting with the leading zero
	for (int j = 0; array[j] == 0 && j < MAXSIZE; j++)
	{
		if (j == (MAXSIZE - 1))
		{
			start = j;
		}
		else if (j != (MAXSIZE - 1))
		{
			start = j + 1;
		}
	}

	// Check if the first digit is not 10 (indicating an integer overflow)
	if (array[0] != 10)
	{
		cout << "Sum: ";

		// Starting at the beginning of the number, this prints the number to the screen
		for (int i = start; i < MAXSIZE; i++)
		{
			cout << array[i];
		}
	}

	// If theres more than 25 characters prompt a error
	else
	{
		cout << "Integer Overflow";
	}

	cout << endl;
}


void getNum(int array[])
{
	// Declare all necessary variables
	char input[MAXSIZE + 1];
	int length;
	bool inputOkay;
	int temp[MAXSIZE];

	do
	{
		inputOkay = true;

		cout << "Enter an integer: ";
		cin.getline(input, MAXSIZE + 1);

		// If user entered more than the max number of digits
		// then make them enter the large integer again
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Integer too long\n";
			cout << "Enter an integer: ";
			cin.getline(input, MAXSIZE + 1);
		}

		// Check to ensure that the user did not enter any non-digit values
		length = strlen(input);

		for (int x = 0; x < length && inputOkay; x++)
		{
			if (!isdigit(input[x]))
			{
				inputOkay = false;
				cout << "Invalid input\n";
			}
		}

	} while (!inputOkay);


	// TODO: Write code for the remaining portion of the function

	// Converts the values of input from ASCII to integer and puts them in temp
	for (int i = 0; i < length; i++)
	{
		temp[i] = input[i] - '0';
	}

	// Moves all the values from the start of temp to the end of array
	for (int i = 0; i < length; i++)
	{
		array[MAXSIZE - length + i] = temp[i];
	}
}

void addition(int arraySum[], int array1[], int array2[])
{
	int sum;

	// This variable tells the program if a value is carried over from the previous addition 
	bool carry = 0;

	// Adds up the 2 numbers and puts them in arraySum
	for (int i = MAXSIZE - 1; i >= 0; i--)
	{
		sum = array1[i] + array2[i];

		// If carry is 1, that means the previous addition had a sum more than 9
		if (carry == 1)
		{
			sum += 1;
		}

		// If the sum is over 9 then you will have to carry over a 1 to the next position
		if (sum > 9)
		{
			arraySum[i] = sum - 10;
			carry = 1;
		}

		// If the sum is less than 9 you don't have to carry anything over 
		else if (sum <= 9)
		{
			arraySum[i] = sum;
			carry = 0;
		}
		// If there is an integer overflow, it will put a 10 in the index 0 of the arraySum creating a value that can be checked for and will never normally occur
		// An integer overflow means that array1[0] and array2[0] add up to a value greater than 9
		if (carry == 1 && i == 0)
		{
			arraySum[0] = 10;
		}
	}
}