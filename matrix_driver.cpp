#include <iostream>
#include "matrix.h"

using namespace std;
using namespace cop4530;

int main() {
	matrix<int> m1(2,3);
	matrix<int> m2(3,2);
	matrix<int> m(2,2);

	m1.setValueAll(1);
	m2.setValueAll(2);

	m = m1 * m2;
	cout << m1 << m2 << endl;
	cout << m << endl;
	return(EXIT_SUCCESS);
}

