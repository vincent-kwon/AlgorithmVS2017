#include <iostream>

using namespace std;

int josepus(int n) {

	return 0;
}
int indexArray[10];
int indexMemo[2][10];

int alive[10] = { 1,1,1,1,1,1,1,1,1,1 };

int chooseNextAlive(int currentKill, int num) {
	for (int i = currentKill + 1; i <= num; i++) {
		if (alive[i] == 1) return i;
	}
	for (int i = 1; i < currentKill; i++) {
		if (alive[i] == 1) return i;
	}
	return -1;
}

int chooseNextKill(int toLive, int num) {
	for (int i = toLive + 1; i <= num; i++) {
		if (alive[i] == 1) return i;
	}
	for (int i = 1; i < toLive; i++) {
		if (alive[i] == 1) return i;
	}
	return toLive;
}

void killNext(int toKill, int num) {
	alive[toKill] = 0;
	int x = chooseNextAlive(toKill, num);
	if (x == -1) {
		cout << "Last:" << toKill << endl;
		return;
	}
	else {
		int y = chooseNextKill(x, num);
		if (y == x) {
			cout << "Last:" << x << endl;
			return;
		}
		else {
			killNext(y, num);
		}
	}
}

void testJosepus() { 
	killNext(2, 8);
}
