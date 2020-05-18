#pragma once

//3rd Party
#include <gmpxx.h>

class Object_Counter{
	public: static mpz_class Get_Number_Of_Objects_In_The_Library(void);
		private: static void Scan_All_The_Sub_Files(mpz_class & number_of_objects); //recursive
	
};
