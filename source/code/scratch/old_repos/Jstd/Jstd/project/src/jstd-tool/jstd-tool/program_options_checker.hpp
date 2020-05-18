#pragma once

//Boost Libraries
#include "program_options.hpp"

class Program_Options_Checker{

	public: static void Check(Program_Options const& program_options);
		private: static void Make_Sure_An_Actual_Task_Is_Being_Performed(Program_Options const& program_options);
		private: static void Make_Sure_The_Cases_Flag_Has_An_Appropiate_Value(Program_Options const& program_options);
		private: static void Make_Sure_At_Least_One_Header_Gaurd_Is_Being_Used(Program_Options const& program_options);


};
