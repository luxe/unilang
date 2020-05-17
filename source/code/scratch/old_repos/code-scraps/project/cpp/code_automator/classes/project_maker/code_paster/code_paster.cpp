#include "code_paster.hpp"
#include <fstream>

//Main Module Code
void Code_Paster::Put_Main_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \"main_parts/includes.hpp\"" << '\n';
	outfile << "#include \"main_parts/generated_namespace.hpp\"" << '\n';
	outfile << "namespace{" << '\n';
	outfile << "namespace constant{" << '\n';
	outfile << "#include \"main_parts/constants.hpp\"" << '\n';
	outfile << "}" << '\n';
	outfile << "#include \"main_parts/function_declerations.hpp\"" << '\n';
	outfile << "}" << '\n';
	outfile << "#include\"main_parts/main_function.hpp\"" << '\n';
	outfile << "namespace{" << '\n';
	outfile << "#include \"main_parts/function_definitions.hpp\"" << '\n';
	outfile << "}" << '\n';
	return;
}
void Code_Paster::Put_Main_Function_File(std::string const& main_function_file){
	
	std::ofstream outfile(main_function_file);
	outfile << "auto main(int argc, char** argv) -> int{\n";
	outfile << "\t\n";
	outfile << "\t//read in program flags\n";
	outfile << "\tstd::unique_ptr<obj::Program_Options> program_options {new obj::Program_Options{argc,argv}};\n";
	outfile << "\t\n";
	outfile << "\t//greet the universe\n";
	outfile << "\tstd::cout << \"hello universe\" << std::endl;\n";
	outfile << "\t\n";
	outfile << "\treturn EXIT_SUCCESS;\n";
	outfile << "}";
	return;
}
void Code_Paster::Put_Main_Driver_Function_File(std::string const& main_function_file){
	
	std::ofstream outfile(main_function_file);
	outfile << "auto main(int argc, char** argv) -> int{\n";
	outfile << "\t\n";
	outfile << "\t//greet the universe\n";
	outfile << "\tstd::cout << \"hello universe\" << std::endl;\n";
	outfile << "\t\n";
	outfile << "\treturn EXIT_SUCCESS;\n";
	outfile << "}";
	return;
}
void Code_Paster::Put_Includes_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \"includes_part/c.hpp\"\n";
	outfile << "#include \"includes_part/c++.hpp\"\n";
	outfile << "#include \"includes_part/3rd_party.hpp\"\n";
	outfile << "#include \"includes_part/project.hpp\"\n";
	return;
}
void Code_Paster::Put_C_Include_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "///C Headers\n";
	outfile << "//#include <assert.h> //(deprecated)\n";
	outfile << "//#include <complex.h> //(deprecated)\n";
	outfile << "//#include <ctype.h> //(deprecated)\n";
	outfile << "//#include <errno.h> //(deprecated)\n";
	outfile << "//#include <fenv.h> //(deprecated)\n";
	outfile << "//#include <float.h> //(deprecated)\n";
	outfile << "//#include <inttypes.h> //(deprecated)\n";
	outfile << "//#include <iso646.h> //(deprecated)\n";
	outfile << "//#include <limits.h> //(deprecated)\n";
	outfile << "//#include <locale.h> //(deprecated)\n";
	outfile << "//#include <math.h> //(deprecated)\n";
	outfile << "//#include <setjmp.h> //(deprecated)\n";
	outfile << "//#include <signal.h> //(deprecated)\n";
	outfile << "//#include <stdalign.h> //(deprecated)\n";
	outfile << "//#include <stdarg.h> //(deprecated)\n";
	outfile << "//#include <stdatomic.h> //(deprecated)\n";
	outfile << "//#include <stdbool.h> //(deprecated)\n";
	outfile << "//#include <stddef.h> //(deprecated)\n";
	outfile << "//#include <stdint.h> //(deprecated)\n";
	outfile << "//#include <stdio.h> //(deprecated)\n";
	outfile << "//#include <stdlib.h> //(deprecated)\n";
	outfile << "//#include <stdnoreturn.h> //(deprecated)\n";
	outfile << "//#include <string.h> //(deprecated)\n";
	outfile << "//#include <tgmath.h> //(deprecated)\n";
	outfile << "//#include <threads.h> //(deprecated)\n";
	outfile << "//#include <time.h> //(deprecated)\n";
	outfile << "//#include <uchar.h> //(deprecated)\n";
	outfile << "//#include <wchar.h> //(deprecated)\n";
	outfile << "//#include <wctype.h> //(deprecated)\n";
	return;
}
void Code_Paster::Put_CPP_Include_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "///General\n";
	outfile << "//#include <algorithm>\n";
	outfile << "//#include <chrono>\n";
	outfile << "//#include <functional>\n";
	outfile << "//#include <iterator>\n";
	outfile << "//#include <locale>\n";
	outfile << "#include <memory>\n";
	outfile << "//#include <stdexcept>\n";
	outfile << "//#include <tuple>\n";
	outfile << "#include <utility>\n";
	outfile << '\n';
	outfile << "///C++ C Headers\n";
	outfile << "//#include <cassert>\n";
	outfile << "//#include <ccomplex>\n";
	outfile << "//#include <cctype>\n";
	outfile << "//#include <cerrno>\n";
	outfile << "//#include <cfenv>\n"; 
	outfile << "//#include <cfloat>\n";
	outfile << "//#include <cinttypes>\n"; 
	outfile << "//#include <ciso646>\n";
	outfile << "//#include <climits>\n";
	outfile << "//#include <clocale>\n";
	outfile << "//#include <cmath>\n";
	outfile << "//#include <csetjmp>\n";
	outfile << "//#include <csignal>\n";
	outfile << "//#include <cstdalign>\n";
	outfile << "//#include <cstdarg>\n";
	outfile << "//#include <cstdbool>\n";
	outfile << "//#include <cstddef>\n";
	outfile << "//#include <cstdint>\n";
	outfile << "//#include <cstdio>\n";
	outfile << "#include <cstdlib>\n";
	outfile << "//#include <cstring>\n";
	outfile << "//#include <cwstring>\n";
	outfile << "//#include <ctgmath>\n";
	outfile << "//#include <ctime>\n";
	outfile << "//#include <cuchar>\n";
	outfile << "//#include <cwchar>\n";
	outfile << "//#include <cwctype>\n";
	outfile << '\n';
	outfile << "///Containers\n";
	outfile << "//#include <array>\n";
	outfile << "//#include <dynarray>\n";
	outfile << "//#include <bitset>\n";
	outfile << "//#include <deque>\n";
	outfile << "//#include <forward_list>\n";
	outfile << "//#include <list>\n";
	outfile << "//#include <map>\n";
	outfile << "//#include <queue>\n";
	outfile << "//#include <set>\n";
	outfile << "//#include <stack>\n";
	outfile << "//#include <unordered_map>\n";
	outfile << "//#include <unordered_set>\n";
	outfile << "#include <vector>\n";
	outfile << "#include <string>\n";
	outfile << '\n';
	outfile << "///Streams and Input/Output\n";
	outfile << "#include <fstream>\n";
	outfile << "#include <iomanip>\n";
	outfile << "//#include <ios>\n";
	outfile << "//#include <iosfwd>\n";
	outfile << "#include <iostream>\n";
	outfile << "//#include <istream>\n";
	outfile << "//#include <ostream>\n";
	outfile << "//#include <sstream>\n";
	outfile << "//#include <streambuf>\n";
	outfile << "//#include <strstream> // (deprecated)\n";
	outfile << '\n';
	outfile << "///Numerics\n";
	outfile << "//#include <complex>\n";
	outfile << "//#include <numeric>\n";
	outfile << "//#include <random>\n";
	outfile << "//#include <valarray>\n";
	outfile << "//#include <ratio>\n";
	outfile << '\n';
	outfile << "///Language support\n";
	outfile << "//#include <exception>\n";
	outfile << "//#include <limits>\n";
	outfile << "//#include <new>\n";
	outfile << "//#include <typeinfo>\n";
	outfile << '\n';
	outfile << "///Thread support library\n";
	outfile << "//#include <thread>\n";
	outfile << "//#include <mutex>\n";
	outfile << "//#include <shared_mutex>\n";
	outfile << "//#include <atomic>\n";
	outfile << "//#include <condition_variable>\n";
	outfile << "//#include <future>\n";
	outfile << '\n';
	outfile << "///Other\n";
	outfile << "//#include <regex>\n";
	outfile << "//#include <codecvt>\n";
	outfile << "//#include <initializer_list>\n";
	outfile << "//#include <system_error>\n";
	outfile << "//#include <type_traits>\n";
	outfile << "//#include <scoped_allocator>\n";
	outfile << "//#include <typeindex>\n";
	outfile << "//#include <optional>\n";
	return;
}
void Code_Paster::Put_3rd_Party_Include_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "///GMP (arbitrary precision arithmetic)\n";
	outfile << "//#include <gmpxx.h>\n";
	outfile << "\n";
	outfile << "///Boost\n";
	outfile << "//#include <boost/aligned_storage.hpp>\n";
	outfile << "//#include <boost/aligned_storage.hpp>\n";
	outfile << "//#include <boost/any.hpp>\n";
	outfile << "//#include <boost/array.hpp>\n";
	outfile << "//#include <boost/asio.hpp>\n";
	outfile << "//#include <boost/assert.hpp>\n";
	outfile << "//#include <boost/assign.hpp>\n";
	outfile << "//#include <boost/atomic.hpp>\n";
	outfile << "//#include <boost/bimap.hpp>\n";
	outfile << "//#include <boost/bind.hpp>\n";
	outfile << "//#include <boost/blank_fwd.hpp>\n";
	outfile << "//#include <boost/blank.hpp>\n";
	outfile << "//#include <boost/call_traits.hpp>\n";
	outfile << "//#include <boost/cast.hpp>\n";
	outfile << "//#include <boost/cerrno.hpp>\n";
	outfile << "//#include <boost/checked_delete.hpp>\n";
	outfile << "//#include <boost/chrono.hpp>\n";
	outfile << "//#include <boost/circular_buffer_fwd.hpp>\n";
	outfile << "//#include <boost/circular_buffer.hpp>\n";
	outfile << "//#include <boost/compressed_pair.hpp>\n";
	outfile << "//#include <boost/concept_archetype.hpp>\n";
	outfile << "//#include <boost/concept_check.hpp>\n";
	outfile << "//#include <boost/config.hpp>\n";
	outfile << "//#include <boost/crc.hpp>\n";
	outfile << "//#include <boost/cregex.hpp>\n";
	outfile << "//#include <boost/cstdint.hpp>\n";
	outfile << "//#include <boost/cstdlib.hpp>\n";
	outfile << "//#include <boost/current_function.hpp>\n";
	outfile << "//#include <boost/date_time.hpp>\n";
	outfile << "//#include <boost/dynamic_bitset_fwd.hpp>\n";
	outfile << "//#include <boost/dynamic_bitset.hpp>\n";
	outfile << "//#include <boost/enable_shared_from_this.hpp>\n";
	outfile << "//#include <boost/exception.hpp>\n";
	outfile << "//#include <boost/exception_ptr.hpp>\n";
	outfile << "//#include <boost/filesystem.hpp>\n";
	outfile << "//#include <boost/flyweight.hpp>\n";
	outfile << "//#include <boost/foreach_fwd.hpp>\n";
	outfile << "//#include <boost/foreach.hpp>\n";
	outfile << "//#include <boost/format.hpp>\n";
	outfile << "//#include <boost/functional.hpp>\n";
	outfile << "//#include <boost/function_equal.hpp>\n";
	outfile << "//#include <boost/function.hpp>\n";
	outfile << "//#include <boost/function_output_iterator.hpp>\n";
	outfile << "//#include <boost/generator_iterator.hpp>\n";
	outfile << "//#include <boost/geometry.hpp>\n";
	outfile << "//#include <boost/get_pointer.hpp>\n";
	outfile << "//#include <boost/implicit_cast.hpp>\n";
	outfile << "//#include <boost/indirect_reference.hpp>\n";
	outfile << "//#include <boost/integer_fwd.hpp>\n";
	outfile << "//#include <boost/integer.hpp>\n";
	outfile << "//#include <boost/integer_traits.hpp>\n";
	outfile << "//#include <boost/intrusive_ptr.hpp>\n";
	outfile << "//#include <boost/io_fwd.hpp>\n";
	outfile << "//#include <boost/is_placeholder.hpp>\n";
	outfile << "//#include <boost/iterator_adaptors.hpp>\n";
	outfile << "//#include <boost/iterator.hpp>\n";
	outfile << "//#include <boost/last_value.hpp>\n";
	outfile << "//#include <boost/lexical_cast.hpp>\n";
	outfile << "//#include <boost/limits.hpp>\n";
	outfile << "//#include <boost/locale.hpp>\n";
	outfile << "//#include <boost/local_function.hpp>\n";
	outfile << "//#include <boost/make_shared.hpp>\n";
	outfile << "//#include <boost/math_fwd.hpp>\n";
	outfile << "//#include <boost/mem_fn.hpp>\n";
	outfile << "//#include <boost/memory_order.hpp>\n";
	outfile << "//#include <boost/mpi.hpp>\n";
	outfile << "//#include <boost/multi_array.hpp>\n";
	outfile << "//#include <boost/multi_index_container_fwd.hpp>\n";
	outfile << "//#include <boost/multi_index_container.hpp>\n";
	outfile << "//#include <boost/next_prior.hpp>\n";
	outfile << "//#include <boost/noncopyable.hpp>\n";
	outfile << "//#include <boost/nondet_random.hpp>\n";
	outfile << "//#include <boost/none.hpp>\n";
	outfile << "//#include <boost/none_t.hpp>\n";
	outfile << "//#include <boost/non_type.hpp>\n";
	outfile << "//#include <boost/operators.hpp>\n";
	outfile << "//#include <boost/optional.hpp>\n";
	outfile << "//#include <boost/parameter.hpp>\n";
	outfile << "//#include <boost/phoenix.hpp>\n";
	outfile << "//#include <boost/pointee.hpp>\n";
	outfile << "//#include <boost/pointer_cast.hpp>\n";
	outfile << "//#include <boost/pointer_to_other.hpp>\n";
	outfile << "//#include <boost/preprocessor.hpp>\n";
	outfile << "//#include <boost/program_options.hpp>\n";
	outfile << "//#include <boost/progress.hpp>\n";
	outfile << "//#include <boost/python.hpp>\n";
	outfile << "//#include <boost/random.hpp>\n";
	outfile << "//#include <boost/range.hpp>\n";
	outfile << "//#include <boost/ratio.hpp>\n";
	outfile << "//#include <boost/rational.hpp>\n";
	outfile << "//#include <boost/ref.hpp>\n";
	outfile << "//#include <boost/regex_fwd.hpp>\n";
	outfile << "//#include <boost/regex.hpp>\n";
	outfile << "//#include <boost/scoped_array.hpp>\n";
	outfile << "//#include <boost/scoped_ptr.hpp>\n";
	outfile << "//#include <boost/scope_exit.hpp>\n";
	outfile << "//#include <boost/shared_array.hpp>\n";
	outfile << "//#include <boost/shared_container_iterator.hpp>\n";
	outfile << "//#include <boost/shared_ptr.hpp>\n";
	outfile << "//#include <boost/signal.hpp>\n";
	outfile << "//#include <boost/signals2.hpp>\n";
	outfile << "//#include <boost/signals.hpp>\n";
	outfile << "//#include <boost/smart_ptr.hpp>\n";
	outfile << "//#include <boost/spirit.hpp>\n";
	outfile << "//#include <boost/static_assert.hpp>\n";
	outfile << "//#include <boost/strong_typedef.hpp>\n";
	outfile << "//#include <boost/swap.hpp>\n";
	outfile << "//#include <boost/thread.hpp>\n";
	outfile << "//#include <boost/throw_exception.hpp>\n";
	outfile << "//#include <boost/timer.hpp>\n";
	outfile << "//#include <boost/token_functions.hpp>\n";
	outfile << "//#include <boost/token_iterator.hpp>\n";
	outfile << "//#include <boost/tokenizer.hpp>\n";
	outfile << "//#include <boost/type.hpp>\n";
	outfile << "//#include <boost/type_traits.hpp>\n";
	outfile << "//#include <boost/unordered_map.hpp>\n";
	outfile << "//#include <boost/unordered_set.hpp>\n";
	outfile << "//#include <boost/utility.hpp>\n";
	outfile << "//#include <boost/variant.hpp>\n";
	outfile << "//#include <boost/version.hpp>\n";
	outfile << "//#include <boost/visit_each.hpp>\n";
	outfile << "//#include <boost/wave.hpp>\n";
	outfile << "//#include <boost/weak_ptr.hpp>\n";
	outfile << "\n";
	outfile << "///Pretty Printers\n";
	outfile << "#include <prettyprint.hpp>\n";
	outfile << "#include <prettyprint98.hpp>\n";
	outfile << "\n";
	outfile << "///My Utility Library\n";
	outfile << "#include <utilities/utilities.hpp>\n";
	
	return;
}
void Code_Paster::Put_Project_Include_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "///Root Project Classes\n";
	return;
}

//Class
void Code_Paster::Put_Class_Header(std::string const& file_name, std::string const& class_name){
	
	std::ofstream outfile(file_name);
	outfile << "#pragma once\n";
	outfile << "#include \"class_parts/deceleration/includes.hpp\"\n";
	outfile << "#include \"class_parts/deceleration/generated_namespace.hpp\"\n";
	outfile << "#include \"class_parts/deceleration/templated.hpp\"\n";
	outfile << "class " << class_name << "\n";
	outfile << "#include \"class_parts/deceleration/parents.hpp\"\n";
	outfile << "{\n";
	outfile << "#include \"class_parts/deceleration/static.hpp\"\n";
	outfile << "#include \"class_parts/deceleration/friend.hpp\"\n";
	outfile << "#include \"class_parts/deceleration/object_functions.hpp\"\n";
	outfile << "#include \"class_parts/deceleration/data.hpp\"\n";
	outfile << "};\n";
	outfile << "#include \"class_parts/definition/templates.hpp\"\n";
	outfile << "}\n";
	
	return;
}
void Code_Paster::Put_Class_Source(std::string const& file_name,std::string const& class_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \"" + class_name + ".hpp\"\n";
	outfile << "#include \"class_parts/definition/includes.hpp\"\n";
	outfile << "#include \"class_parts/definition/generated_namespace.hpp\"\n";
	outfile << "#include \"class_parts/definition/static.hpp\"\n";
	outfile << "#include \"class_parts/definition/friend.hpp\"\n";
	outfile << "#include \"class_parts/definition/object_functions.hpp\"\n";
	outfile << "}\n";
	return;
}
void Code_Paster::Put_Class_Static_Part(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \"static_part/functions.hpp\"" << '\n';
	outfile << "#include \"static_part/data.hpp\"" << '\n';
	return;
}
void Code_Paster::Put_Class_Object_Functions_Part(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \"object_functions_part/constructors.hpp\"" << '\n';
	outfile << "#include \"object_functions_part/observers.hpp\"" << '\n';
	outfile << "#include \"object_functions_part/transformers.hpp\"" << '\n';
	outfile << "#include \"object_functions_part/overloaded_operators.hpp\"" << '\n';
	outfile << "#include \"object_functions_part/casts.hpp\"" << '\n';
	outfile << "#include \"object_functions_part/destructor.hpp\"" << '\n';
	
	return;
}

//Program_Options
void Code_Paster::Put_Program_Options_Decleration_Constructor(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "public: explicit Program_Options(int const& argc, char** const& argv);\n";
		
	return;
}
void Code_Paster::Put_Program_Options_Definition_Constructor(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "#include \".scope_constructor.hpp\"\n";
	outfile << "(int const& argc, char** const& argv){\n";
	outfile << "using namespace boost::program_options;\n";
	outfile << "\t\n";
	outfile << "//build all the possible flags and add description.\n";
	outfile <<  "options_description desc (Get_Options_Description());\n";
	outfile << "\t\n";
	outfile << "//set positional arguments\n";
	outfile << "positional_options_description pod;\n";
	outfile << "//pod.add(\"something\",-1);\n";
	outfile << "\t\n";
	outfile << "//build variable map\n";
	outfile << "Build_Variable_Map(argc,argv,desc,pod);\n";
	outfile << "Process_Immediate_Options(desc);\n";
	outfile << "}";
	
	return;
}
void Code_Paster::Put_Program_Options_Decleration_Transformer_Functions(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "private: boost::program_options::options_description Get_Options_Description(void);\n";
	outfile << "private: void Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod);\n";
	outfile << "private: void Process_Immediate_Options(boost::program_options::options_description const& desc);\n";
		
	return;
}
void Code_Paster::Put_Program_Options_Definition_Transformer_Functions(std::string const& file_name){
	
	std::ofstream outfile(file_name);
std::string str = R"DELIM(
#include ".scope_function.hpp"
Get_Options_Description(void) -> boost::program_options::options_description{
	using namespace boost::program_options;
	
	//Program Description
	options_description desc("This program does something");
	
	//Program Flags
	desc.add_options()
	
	("help,h","produce this help message")
	("version,v","display version");
	
	return desc;
}
#include ".scope_function.hpp"
Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void{
	using namespace boost::program_options;
	
	//store user flag data.  crash elegantly if they pass incorrect flags.
	try{
		store(command_line_parser(argc, argv).options(desc).positional(pod).run(), vm);
		notify(vm);
	}
	catch(error& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		std::cerr << desc << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return;
}
#include ".scope_function.hpp"
Process_Immediate_Options( boost::program_options::options_description const& desc) -> void{
	
	//do not continue the program if the user wanted to see the version or help data
	if (vm.count("version")){
		std::cout << "\nThis is version " << VERSION_NUMBER << " of the Code Automating Tool.\n\n";
		exit(EXIT_SUCCESS);
	}
	else if (vm.count("help")){
		std::cout << '\n' << desc << '\n';
		exit(EXIT_SUCCESS);
	}
	
	return;
}
)DELIM";
	
	outfile << str;
		
	return;
}
void Code_Paster::Put_Program_Options_Decleration_Data(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "private: boost::program_options::variables_map vm;\n";
		
	return;
}
void Code_Paster::Put_Program_Options_Definition_Data(std::string const& file_name){
	
	std::ofstream outfile(file_name);
		
	return;
}
void Code_Paster::Put_Program_Options_Decleration_Static_Data(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "private: static const std::string VERSION_NUMBER;\n";
		
	return;
}
void Code_Paster::Put_Program_Options_Definition_Static_Data(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "const std::string\n #include \".scope_data.hpp\"\nVERSION_NUMBER = \"1\";\n";
		
	return;
}

//Rules Files Code
void Code_Paster::Put_Code_Root_Rules_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := classes main_modules";
	return;
}
void Code_Paster::Put_Root_Rules_File(std::string const& file_name){
	
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := code";
	return;
}
void Code_Paster::Put_Main_Modules_Rules_File(std::string const& file_name, std::vector<std::string> const& main_module_names){
	
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := ";
	for (auto main_module_name: main_module_names){
		outfile << main_module_name << " ";
	}
	return;
}
void Code_Paster::Put_Main_Module_Rules_File(std::string const& file_name,std::string const& main_module_name){
	
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := direct_relationships\n";
	outfile << "TARGETS := " << main_module_name << "\n";
	outfile << main_module_name << "_DEPS = " << main_module_name << ".o $(TARGETS_$(d)/direct_relationships/program_options/class)\n";
	outfile << main_module_name << "_LIBS = -lboost_program_options\n";
	return;
}
void Code_Paster::Put_Main_Driver_Rules_File(std::string const& file_name,std::string const& main_module_name){
	
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := direct_relationships\n";
	outfile << "TARGETS := " << main_module_name << "\n";
	outfile << main_module_name << "_DEPS = " << main_module_name << ".o\n";
	outfile << main_module_name << "_LIBS = \n";
	return;
}
void Code_Paster::Put_Drivers_Rule_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := driver0";
	return;
}
void Code_Paster::Put_Main_Module_DR_Rules_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := program_options";
	return;
}
void Code_Paster::Put_Main_Driver_DR_Rules_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := ";
	return;
}
void Code_Paster::Put_Main_Module_Root_Rules_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := main";
	return;
}
void Code_Paster::Put_Tests_Rule_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := drivers";
	return;
}
void Code_Paster::Put_Class_Root_Rules_File(std::string const& file_name){
	 std::ofstream outfile(file_name);
	 outfile << "SUBDIRS := program_options";
	 return;
 }
void Code_Paster::Put_Class_Name_Rules_File(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := class tests";
	return;
}
void Code_Paster::Put_Class_Rules_File(std::string const& file_name, std::string const& class_name){
	std::ofstream outfile(file_name);
	outfile << "SUBDIRS := direct_relationships\n";
	outfile << "TARGETS := " << class_name << ".o";
	return;
}

