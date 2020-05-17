#include <iostream>
#include <string>

int main() {

	enum MONTH {JANUARY, FEBRUARY,  MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMEMBER, DECEMBER};
	enum SEASON {WINTER, SPRING, SUMMER, AUTUMN};

	MONTH month;
	SEASON season;

	switch (month) {
		case DECEMBER:
		case JANUARY:
		case FEBRUARY:
			season = WINTER;
			break;

		case MARCH:
		case APRIL:
		case MAY:
			season = SPRING;
			break;

		case JUNE:
		case JULY:
		case AUGUST:
			season = SUMMER;
			break;

		default:
			season = AUTUMN;
	}


}
