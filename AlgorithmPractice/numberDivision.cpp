#include <iostream>
using namespace std;

int resultArray[10];

void getDivision(int number, int maxDivision, int arrayIndex) {

	if (number == 0) {
		for (int i = 0; i < arrayIndex; i++)
			cout << resultArray[i] << " ";
		cout << "" << endl;
		return;
	}

	if (number < maxDivision) maxDivision = number;
	for (int i = 1; i <= maxDivision; i++) {
		resultArray[arrayIndex] = i;
		getDivision(number - i, i, arrayIndex + 1);
	}
}

void testNumberDivision() {
	getDivision(5, 3, 0);
}