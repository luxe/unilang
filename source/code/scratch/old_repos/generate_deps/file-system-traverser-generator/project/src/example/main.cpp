#include <iostream>
#include "file_system_traverser.hpp"
#include "utilities.hpp"

// Driver for the File System Traverser
int main(int const argc, char** const argv) {


	// construct the object to do a in-order traversal of your files.
	// it DOES NOT traverse folders at the same level alphabetically.
	File_System_Traverser file_system_traverser(std::vector<std::string>{"MEOWWWWW"});


	// this cluster of code just shows you how the thing actually works function by function call.
	// if you did use it this way, you will see that eventually calling the function "Move_Into_Next_Directory()"
	// will do nothing.  Well that's because you've already traversed the whole tree and you are back where you started.
	// So if you continue calling the function after the traversal,  you just won't move.
	// Also note, this function returns a bool telling you telling you whether you've finished the traversal or not.
	// I've cout'ed it, just so you can see that it prints false,  all the way until you're finished, in which case,
	// calling the function no longer changes directories and instead returns false.
	std::cout <<  std::boolalpha;
	std::cout << "NON-LOOPING DEMONSTRATION:\n";
	std::cout << "--------------------------\n";
	std::cout << "starting at: " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();          // <- after this function,  you are a layer deep
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory(); // <- we've already looked at every directory.
	std::cout << " " << exec("pwd") <<  '\n';                       // this function needs to be called,  in order
	std::cout <<  file_system_traverser.Move_Into_Next_Directory(); // to bring us back to where we started,  but it
	std::cout << " " << exec("pwd") <<  '\n';                       // will also return false.
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout <<  file_system_traverser.Move_Into_Next_Directory();
	std::cout << " " << exec("pwd") <<  '\n';
	std::cout << "ended at: " <<  exec("pwd") <<  '\n';
	// if you ran this chunk of code in the directory set-up it came in, the output would look something like this:
	// starting at: wherever-you-downloaded-it-to/File-System-Traverser/src
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A/world
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A/hello
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B/meow
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B/meow/MEOWWWWW
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C/yup
	// true /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C/hi
	// false /wherever-you-downloaded-it-to/File-System-Traverser/src
	// false /wherever-you-downloaded-it-to/File-System-Traverser/src
	// false /wherever-you-downloaded-it-to/File-System-Traverser/src

	//HOWEVER! YOU WON'T BE USING IT LIKE THE ABOVE WAY! LET ME
	//RESET IT FOR YOU, AND SHOW YOU HOW YOU SHOULD USE IT!
	file_system_traverser.Reset();
	std::cout << "\nLOOPING DEMONSTRATION:\n";
	std::cout << "--------------------------\n";
	std::cout << "starting at: " << exec("pwd") <<  '\n';
	while (file_system_traverser.Move_Into_Next_Directory()) {

		//do something in said folder
		std::cout << exec("pwd") <<  '\n';
	}
	std::cout << "ended at: " <<  exec("pwd") <<  '\n';
	// if you ran this chunk of code in the directory set-up it came in, the output would look something like this:
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A/world
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/A/hello
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B/meow
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/B/meow/MEOWWWWW
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C/yup
	// /wherever-you-downloaded-it-to/File-System-Traverser/src/test_folder/C/hi

	return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------------


