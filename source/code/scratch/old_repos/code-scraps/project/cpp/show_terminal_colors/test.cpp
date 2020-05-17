#include <iostream>
#include "ccolor.h"

using namespace std;

int main()
{
	cout << zkr::cc::fore::red << "This is red text. "
	     << zkr::cc::console << "And changing to console default color."
	     << endl;

	return 0;
}
