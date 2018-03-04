#include <iostream>
#include <string>

using namespace std;

int tsp2[4][4] = {
	{0, 1, 15, 6},
	{2, 0, 7, 3},
	{9, 6, 0, 12},
	{10, 4, 8, 0}
};

int getTsp(int startNode, int midNode, int endNode, unsigned char flagByte, int remainings) {
	cout << "TSP:" << startNode << "," << midNode << "," << endNode << "," << flagByte << endl;
	if (remainings == 0) {
		// if all 4 flag is set then s -> e should return
		return tsp2[startNode][midNode] + tsp2[midNode][endNode];
	}
	else {
		// choose one of not turned on bit and set it as end bit and recursively call getTsp
		unsigned char bit = 1;
		int tmpMin = INT_MAX;
		for (int i = 0; i < 4; i++) {
			bit = 1 << i;
			if ((bit & flagByte) == 0) {
				int thisMin = getTsp(startNode, i, midNode, flagByte | bit, remainings - 1) + tsp2[midNode][endNode];
				if (thisMin < tmpMin) tmpMin = thisMin;
			}
		}
		return tmpMin;
	}
}

int testTSP2() {
	int thisMin = INT_MAX;
	unsigned char flagByte;
	for (int i = 1; i <= 3; i++) {
		flagByte = 0;
		flagByte |= 1; // start index set
		flagByte |= (1 << i);
		int tmp = getTsp(0, i, 0, flagByte, 2);
		if (tmp < thisMin) thisMin = tmp;
	}
	cout << "TSP2: " << thisMin <<  endl;
	return 0;
}

