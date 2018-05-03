#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <functional>

using namespace std;
static bool abs_compare(int a, int b)
{
	return (std::abs(a) < std::abs(b));
}
int test20180305() {
	//vector
	vector<int> v;
	v.push_back(100);
	v.push_back(200);
	v.insert(v.begin() + 1, 300);
	for (int vE : v) {
		cout << vE << endl;
	}
	vector<int>::iterator itor = v.begin();
	for (itor; itor != v.end(); itor++) cout << "itor:" << *itor << endl;

	//list
	list<int> l;
	l.push_front(1000);
	l.push_back(2000);
	for (int lE : l) {
		cout << lE << endl;
	}
	list<int>::iterator litor = l.begin();
	for (litor; litor != l.end(); litor++) {
		cout << "litor: " << *litor << endl;
		l.insert(litor, 8000);
		break;
	}
	for (int lE : l) {
		cout << "AF:" << lE << endl;
	}

	for_each(l.begin(), l.end(), [=](int x) { cout << "lambda: " << x << endl; });
	
	list<int>::iterator vIter = max_element(l.begin(), l.end());
	cout << "lmax: " << *vIter << endl;

	all_of(l.begin(), l.end(), [=](int i) -> bool { cout << "only " << i;  return i < 2000; });
	//map
	map<string, int> m;
	m["abc"] = 1000;
	m["def"] = 2000;
	map<string,int>::iterator value = m.find("abc");
	cout << value->first << "," << value->second << endl;
	std::pair<string, int> ps = *value;
	cout << ps.first << ", " << ps.second << endl ;

	map<string, int>::iterator value2 = m.begin();

	for (value2; value2 != m.end(); value2++)  cout << "itor: " << value2->first << ", " << value2->second << endl;
	m.erase("def");
	
	string s = "ABCD";
	cout << s.size() << endl;
	cout << s.substr(1, s.size() - 1) << endl;
	cout << s.append("EFG") << endl;
	cout << s.at(1) << endl;
	cout << s.find_first_of('F') << endl;
	cout << s.at(s.find_first_not_of('A')) << endl;
	//array
	//memory
	//bit operation

	return 0;
}