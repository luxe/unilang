//Trevor Hickey
//Dan Bennett
//230 Night
//04/11/11
//This driver was used to test the LargeIntegerT class

#include <iostream>
#include "LargeInteger.h"

using namespace std;

int main(){
//╔══════════════════════╗
//║     Constructors     ║
//╚══════════════════════╝

	//default constructor
	LargeIntegerT largeInteger1;

	//constructor with long
	LargeIntegerT largeInteger2(4895);
	LargeIntegerT largeInteger3(-567);
	LargeIntegerT largeInteger4(0);

	//constructor with largeNumberT
	LargeIntegerT largeInteger5(largeInteger2);
	LargeIntegerT largeInteger6(largeInteger3);
	LargeIntegerT largeInteger7(largeInteger4);

	//constructor with a string
	LargeIntegerT largeInteger8("2389");
	LargeIntegerT largeInteger9("-378");
	LargeIntegerT largeInteger10("0");

	LargeIntegerT largeInteger11("000");
	LargeIntegerT largeInteger12("000000012345678987654321");
	LargeIntegerT largeInteger13("-00034");
	LargeIntegerT largeInteger14("-0");

//╔══════════════════════╗
//║      Operations      ║
//╚══════════════════════╝

	//comparision testing
	/*
	cout << (largeInteger2 < largeInteger3) << endl; //0
	cout << (largeInteger3 < largeInteger2) << endl; //1
	cout << (largeInteger2 < 0)  << endl;            //0
	cout << (largeInteger2 < 1)  << endl;            //0
	cout << (largeInteger2 < -1)  << endl;           //0
	cout << (largeInteger2 < 4895)  << endl;         //0
	cout << (largeInteger2 < 4896)  << endl;         //1
	cout << (largeInteger2 < 4894)  << endl;         //0
	cout << (largeInteger2 < -4895)  << endl;        //0
	cout << (largeInteger2 < -4896)  << endl;        //0
	cout << endl;
	cout << (largeInteger2 > largeInteger3) << endl; //1
	cout << (largeInteger3 > largeInteger2) << endl; //0
	cout << (largeInteger2 > 0)  << endl;            //1
	cout << (largeInteger2 > 1)  << endl;            //1
	cout << (largeInteger2 > -1)  << endl;           //1
	cout << (largeInteger2 > 4895)  << endl;         //0
	cout << (largeInteger2 > 4896)  << endl;         //0
	cout << (largeInteger2 > 4894)  << endl;         //1
	cout << (largeInteger2 > -4895)  << endl;        //1
	cout << (largeInteger2 > -4896)  << endl;        //1
	*/
	
	//testing addition and subtraction
	/*
	LargeIntegerT number1("100");
	LargeIntegerT number2("4895");
	LargeIntegerT number3("1234");
	LargeIntegerT number4("23452");
	LargeIntegerT number5("84567");
	LargeIntegerT number6("98764");
	LargeIntegerT number7("562824");
	LargeIntegerT number8("432123");
	LargeIntegerT number9("432123");
	LargeIntegerT number10("647584");
	LargeIntegerT number11("-432");
	LargeIntegerT number12("426692");
	LargeIntegerT number13("-65741");
	LargeIntegerT number14("-65741");
	LargeIntegerT number15("-65872");
	cout << number1 + number2     << endl;   //4995
	cout << number2 + 984         << endl;   //5879
	cout << number1 + number3     << endl;   //1334
	cout << number2 + number3     << endl;   //6129
	cout << number4 + 8213        << endl;   //31665
	cout << number5 + 74329       << endl;   //158896
	cout << number6 + number7     << endl;   //661588
	cout << number8 + 124         << endl;   //432247
	cout << number9 + number1     << endl;   //432223
	cout << number10 + number11   << endl;   //647152
	cout << number9 + number12    << endl;   //858815
	cout << number12 + number13   << endl;   //360951
	cout << number13 + number14   << endl;   //-131482
	cout << number14 + number15   << endl;   //-131613
	cout << number13 + 73627      << endl;   //7886
	cout << number2 - number1     << endl;   //4795
	cout << number7 - number6     << endl;   //464060
	cout << number10 - 46352      << endl;   //601232
	cout << number15 - number11   << endl;   //-65440
	cout << number1 - number14    << endl;   //65841
	cout << number13 - (-7635)    << endl;   //-58106
	cout << number3 - (4321)      << endl;   //-3087
	*/

	//tests multiplication
	/*
	LargeIntegerT number1("10");
	LargeIntegerT number2("48");
	LargeIntegerT number3("1234");
	LargeIntegerT number4("25");
	LargeIntegerT number5("84");
	LargeIntegerT number6("100");
	LargeIntegerT number7("225");
	LargeIntegerT number8("410");
	LargeIntegerT number9("550");
	LargeIntegerT number10("647");
	LargeIntegerT number11("-432");
	LargeIntegerT number12("-721");
	LargeIntegerT number13("-6570");
	LargeIntegerT number14("-10510");
	LargeIntegerT number15("-15000");
	cout << number1 * number2       << endl;   //480
	cout << number1 * number3       << endl;   //12340
	cout << number3 * number2       << endl;   //59232
	cout << number4 * 124           << endl;   //3100
	cout << number5 * number6       << endl;   //8400
	cout << number7 * 650           << endl;   //146250
	cout << number8 * number9       << endl;   //225500
	cout << number10 * 743          << endl;   //480721
	cout << number11 * number1      << endl;   //-4320
	cout << number12 * 2224         << endl;   //-1603504
	cout << number13 * number4      << endl;   //-164250
	cout << number14 * 2863         << endl;   //-30090130
	cout << number15 * number4      << endl;   //375000
	cout << number8 * 457           << endl;   //187370
	cout << number3 * 4321          << endl;   //5332114
	cout << number7 * 4325          << endl;   //973125
	cout << number11 * number12     << endl;   //311472
	cout << number14 * 7584         << endl;   //-79707840
	cout << number5 * (-3645)       << endl;   //-306180
	cout << number9 * (-7893)       << endl;   //-4341150
	cout << number10 * number7      << endl;   //145575
	cout << number13 * (-85764)     << endl;   //563469480
	*/

	//tests division
	/*
	LargeIntegerT number1("5");
	LargeIntegerT number2("10");
	LargeIntegerT number3("1234");
	LargeIntegerT number4("25");
	LargeIntegerT number5("84");
	LargeIntegerT number6("100");
	LargeIntegerT number7("225");
	LargeIntegerT number8("410");
	LargeIntegerT number9("550");
	LargeIntegerT number10("647");
	LargeIntegerT number11("-432");
	LargeIntegerT number12("-721");
	LargeIntegerT number13("-6570");
	LargeIntegerT number14("-10510");
	LargeIntegerT number15("-15000");
	cout << number2 / number1       << endl;   //2
	cout << number1 / 1             << endl;   //5
	cout << number3 / number2       << endl;   //123
	cout << number4 / number1       << endl;   //5
	cout << number5 / number4       << endl;   //3
	cout << number7 / number2       << endl;   //22
	cout << number8 / 43            << endl;   //9
	cout << number10 / number6      << endl;   //6
	cout << number11 / 52           << endl;   //-8
	cout << number12 / 36           << endl;   //-20
	cout << number13 / number6      << endl;   //-65
	cout << number14 / number8      << endl;   //-25
	cout << number15 / number3      << endl;   //-12
	cout << number8  / number2      << endl;   //41
	cout << number3  / 231          << endl;   //5
	cout << number7  / number4      << endl;   //9
	cout << number11 / 64           << endl;   //-6
	cout << number14 / number7      << endl;   //-46
	cout << number5  / number2      << endl;   //8
	cout << number9  / (-69)        << endl;   //-7
	cout << number10 / 94           << endl;   //6
	cout << number13 / number15     << endl;   //0
	*/

	return 0;
}