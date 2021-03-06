#include <iostream>
#include <vector>

using namespace std;

int std_vector() {
	vector<int> v;
	v.push_back(1);
	v.push_back(100);
	v.pop_back();
	v.push_back(500);
	for (int i : v) cout << i << endl; // memo-201706 : please memorize it

	vector< vector <int> > twodimen(10, vector<int>(20, 0));

	twodimen[9][19] = 1000;
	cout << twodimen[9][19] << endl;


	vector<int>::iterator itor = v.begin();

	for (; itor != v.end(); itor++) {
		cout << *itor << " ";
	}
	return 0;
}
