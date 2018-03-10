#include <iostream>

using namespace std;

int testTripleForLoops()
{
	int x = 0;
	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++)
			for (int k = j; k < 10; k++) {
				x++;
				cout << i << "," << j << "," << k << ":" << x << endl;
			}

	cout << x << endl;
	return 0;
}