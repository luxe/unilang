// just make sure the library builds and links
#include "utilities.hpp"
#include <iostream>
#include <string>

int main() {

	std::cout << std::boolalpha;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("file.txt","test1") << std::endl;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("file.txt/","test1/") << std::endl;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("file.txt/","./test1/") << std::endl;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("sdf.txt","test1") << std::endl;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("sdf.txt","test1/") << std::endl;
	std::cout << Path_Contains_File_With_Same_Basename_As_File("sdf.txt","./test1/") << std::endl;
	std::cout << "--" << std::endl;

	Delete_Files_That_Exist_In_Second_Dir_But_Not_In_First_Based_On_Basename("based_on","delete_from");

}
