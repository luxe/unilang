#pragma once
#include <iostream>
/*

*/
class Class_Maker{

	public: static void Make_Class(std::string const& path, std::string const& name);
		private: static std::string Uppercase(std::string str);
		private: static std::string Lowercase(std::string str);
		
			private: static std::string exec(std::string const& cmd);
	private: static std::string exec(const char* cmd);
		private: static bool File_Exists(std::string const& filename);

};