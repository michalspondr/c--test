/*
 * This code compares difference in speed of use of move constructor and copy constructor
 *
 *
 * How to build:
 * gcc -std=c++11 -o move_example move_example.cc
 *
 * Example output:
 * Copy constructor: 0.481086 seconds
 * Move constructor: 1e-06 seconds
 *
 */

#include <vector>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	const size_t size = 20000000;
	vector<string> s1(size);
	clock_t t;
	
	// fill vector with some strings
	for (auto & s : s1) {
		s = "'size' occurences of this string in s1 vector.";
	}

	// copy constructor used
	t = clock();
	vector<string> s2(s1);
	t = clock() - t;
	cout << "Copy constructor: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << endl;

	// move constructor used
	t = clock();
	vector<string> s3(static_cast<vector<string>&&>(s1));
	t = clock() - t;
	cout << "Move constructor: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}
