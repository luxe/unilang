#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long double pi = 4.0;
	long double tempPi;
	for (int i = 1, j = 3; i <= 100000000; i++, j+=2)
	{
		tempPi = static_cast<double>(4)/j;
		if (i%2 != 0)
		{
			pi -= tempPi;
	}
		else if (i%2 == 0)
		{
	cout << "Pi has the value of: " << setprecision(16) << fixed << pi << endl;
	return 0;
    sd
	
}
