//Micah Pennington
//January 25 2022 ©
//Chapter 7 Program

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

	//Step 1 | The following arrays created:
	//an array of double with 5 elements, dArr
	double dArr[5];
	//an array of long, lArr, with 7 elements and initialized at the time of creation with the values 100000, 134567, 123456, 9, -234567, -1, 123489
	long lArr[7] = { 100000, 134567, 123456, 9, -234567, -1, 123489 };
	//a 2 dimensional array of integer, with 3 rows and 5 columns, iArr.
	int iArr[3][5];
	//an array of char with your name initialized in it.Big enough for 30 typable characters, sName.
	char sName[31] = { 'M', 'i', 'c', 'a', 'h', ' ', 'P', 'e', 'n', 'n', 'i', 'n', 'g', 't', 'o', 'n' };

	//Step 2 | define 3 variables, , cnt1 and cnt2 (short data types) as general purpose counters and a long double total
	short cnt1;
	short cnt2;
	long double total = 0;

	//Step 3 | define 1 long variable called highest
	long highest;

	//Step 4 | a for loop to put a random number into each of the elements of the array of double, dArr.
	//Use rand() and seed a random starting point with srand() as demonstrated in Chapter .
	//Use a for loop to display all of the values in dArr.
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++) dArr[i] = (double)rand();
	cout << "Values in dArr:\n";
	for (double d : dArr) cout << d << '\n';

	//Step 5 | another for loop to add up the array of double, dArr, into the variable total
	for (double d : dArr) total += d;

	//Step 6 | one cout to print the total and another cout to print the average of the double array, dArr.
	cout << "The total of dArr is: " << total << '\n';
	cout << "The average of dArr is: " << total / 5.0 << '\n';

	//Step 7 | a for loop similar to the following for the long array, lArr
	for (cnt1 = 1, highest = lArr[0]; cnt1 < 7; cnt1++) {
		//logic to compare each array element, starting with lArr[1], with highest
		//replace highest if the value in lArr[cnt]  is higher than the value in variable highest
		if (lArr[cnt1] > highest) highest = lArr[cnt1];
	}

	//Step 8 | a cout to print highest as derived in the above code
	cout << "The highest value in lArr is: " << highest;

	//Step 9 | a for loop to put a random number, each with a value no lower than 1 and no higher than 53, into each element of iArr, the array of integer, 
	//seed the random generator with srand( (unsigned) time(NULL)). Only have to run srand once….
	//Use the modulo operator similar to the way you did with dice rolls in Project 2.
	srand((unsigned)time(NULL));
	for (int i1 = 0; i1 < 3; i1++) {
		for (int i2 = 0; i2 < 5; i2++) {
			iArr[i1][i2] = rand() % 53 + 1;
		}
	}
	cout << "\n\n";

	//Step 10 | a separate loop to print iArr with 3 rows on your screen. Each row has 5 numbers.
	//Use setw to control the width of each column. See Chapter 3 for an example of a program using setw. Print row by row.
	cout << "Table representing iArr: \n";
	for (int i1 = 0; i1 < 3; i1++) {
		for (int i2 = 0; i2 < 5; i2++) {
			cout << setw(4) << iArr[i1][i2];
		}
		cout << '\n';
	}

	//Step 11 | a loop to print the 2 dimensional array, iArr,
	//so that all 3 numbers in column 0 are printed and then on the next line all 3 numbers in column 1, etc. thru column 4. Print column by column.
	cout << "Table representing column by column iArr: \n";
	for (int i2 = 0; i2 < 5; i2++) {
		for (int i1 = 0; i1 < 3; i1++) {
			cout << setw(4) << iArr[i1][i2];
		}
		cout << '\n';
	}

	//Step 12 | Use cin.getline( ...... ) to type another name into the variable sName. You must use getline with cin to allow space between first and last name.
	cout << "Please enter a name: ";
	cin.getline(sName, 31);

	//Step 13 | Print the ascii value of each character in the char array, 1 per line. Use a while loop and look for the '\0' as a signal to end.
	cout << "Ascii values of name: \n";
	cnt1 = 0;
	while (sName[cnt1] != '\0') {
		cout << (int)sName[cnt1] << '\n';
		cnt1++;
	}

	//Step 14 | make the array of char, sName, have the name "Albert Einstein" in it. You must use strcpy_s function.
	strcpy_s(sName, "Albert Einstein");

	//Step 15 | print the ascii value of the 12th character of the string sName
	cout << "Ascii value of 12th char in sName: " << (int)sName[11] << '\n';

	//Step 16 | Define a pointer to a double, pdArray.
	double* pdArray;

	//Step 17 | Assign the pointer, pdArray, to contain the address of the double array, dArr:
	pdArray = dArr;

	//Step 18 | Use the array name, dArr, to print out the array elements with subscript notation, [ ]. All on 1 line a space between each.
	for (int i = 0; i < 5; i++) cout << dArr[i] << ' ';
	cout << '\n';

	//Step 19 | Use the pointer to print out the array elements with pointer notation while not changing the pointer itself.
	//Use a for loop. *( pdArray + Cnt1) would be an example. All on 1 line a space between each.
	for (int i = 0; i < 5; i++) cout << *( pdArray + i ) << ' ';
	cout << '\n';

	//Step 20 | Use the pointer to print out the array elements with pointer notation but change the pointer to point to the actual array element
	//rather than the method in 18. All on 1 line. *pdArray would do this if the loop has the following post loop operation : pdArray++
	for (; pdArray <= &dArr[4]; pdArray++) cout << *pdArray << ' ';
	cout << '\n';

	//Step 21 | Use the array name for the double array and pointer notation to print the entire array, all on one line.
	for (int i = 0; i < 5; i++) cout << *( dArr + i ) << ' ';
	cout << '\n';

	//Step 22 | Using a different pointer, piArray, allocate enough memory for 100 int's and assign the address to the pointer.
	int* piArray = new int[100];

	//Step 23 | In a for loop assign every item in the array to be a random number from 1 to 49 ( hint: rand() % 6 + 1 gives random numbers from 1 to 6 )
	for (int i = 0; i < 100; i++) *( piArray + i ) = rand() % 49 + 1;

	//Step 24 | Using cout print the first 10 items in the array, all on 1 line.
	for (int i = 0; i < 10; i++) cout << *( piArray + i ) << ' ';
	cout << '\n';

	return EXIT_SUCCESS;
}