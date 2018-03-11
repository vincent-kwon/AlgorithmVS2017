#include <iostream>
#include "combinational.h"

using namespace std;

// n == r => 1
// n > 0, r = 0 => 1
// n = 0, r > 0 => 0
int memo[6][6] = { 0, };

int getCombinational(int n, int r) {
	if (memo[n][r] != -1) return memo[n][r];
	if (n == r) return memo[n][r] = 1;
	if (n > 0 && r == 0) return memo[n][r] = 1;
	if (n == 0) return memo[n][r] = 0;

	return memo[n][r] = (getCombinational(n - 1, r) + getCombinational(n - 1, r - 1));
}

void testCombinational() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			memo[i][j] = -1;
	int r = getCombinational(5, 2);
	cout << "r: " << r << endl;
}
