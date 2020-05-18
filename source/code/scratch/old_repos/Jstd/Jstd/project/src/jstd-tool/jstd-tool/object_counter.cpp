#include "object_counter.hpp"
#include "utilities.hpp"

mpz_class Object_Counter::Get_Number_Of_Objects_In_The_Library(void){
	mpz_class number_of_objects = 0;
	
	Scan_All_The_Sub_Files(number_of_objects);
	
	return number_of_objects;
}
void Object_Counter::Scan_All_The_Sub_Files(mpz_class & number_of_objects){
	
	//get all the directories of the pseudo library node
	auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());
	//++number_of_objects;
	
	//*every node/folder will be a namespace.
	//hit every node and count it.
	for (auto const& dir: dirs){
		++number_of_objects;
		Step_Into_Folder(dir);
		Scan_All_The_Sub_Files(number_of_objects);
		Step_Out_Of_Folder();
	}
	
	if (dirs.empty()){
		++number_of_objects;
	}
	
	//std::cout << number_of_objects.get_str() << std::endl;
	
	return;
}