#include <iostream>
using namespace std;

int DAYS = 20;
int LAS_TOTAL = 1;
int LAS_NOISSUE = 0;
double LAS_NOISSUE_PERCENT = 0;

void checkAbsent(int day, int continousLate) {
	if (day == DAYS) {
		LAS_NOISSUE++;
		return;
	}
	else {
		// less
		checkAbsent(day + 1, 0); // not late case
		if (continousLate < 2) {
			checkAbsent(day + 1, continousLate + 1); // proceed only when 0, 1, 
		}
	}
}

void checkAbsentPercent(int day, int continousLate, double prevPercent) {
	if (day == DAYS) {
		LAS_NOISSUE_PERCENT += prevPercent;
		return;
	}
	else {
		// less
		checkAbsentPercent(day + 1, 0, prevPercent * 0.5); // not late case
		if (continousLate < 2) {
			checkAbsentPercent(day + 1, continousLate + 1, prevPercent * 0.5); // proceed only when 0, 1, 
		}
	}
}

int testLeaveAbscentCheck() {
    
	for (int i = 0; i < 20; i++) {
		LAS_TOTAL = LAS_TOTAL * 2;
	}
	checkAbsent(0, 0);
	cout << "Total: " << LAS_TOTAL << ", no issue: " << LAS_NOISSUE << endl;

	cout << "Now in % " << endl;
	checkAbsentPercent(0, 0, 1);
	cout << "No Issue %: " << LAS_NOISSUE_PERCENT << endl;
	double t = (double) LAS_NOISSUE / LAS_TOTAL;
	cout << "Verify: " << t << endl;
	return 0;
}