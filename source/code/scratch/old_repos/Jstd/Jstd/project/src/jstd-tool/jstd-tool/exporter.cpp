#include "exporter.hpp"
//#include "global.hpp"
//#include "utilities.hpp"
//#include "function_expression_generator.hpp"
#include <string>
#include <vector>
#include <fstream>

//3rd Party
#include <gmpxx.h>

void Exporter::Export_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time) {

	if (program_options.Export()){
		Perform_Timed_Export(program_options, last_run_time);
	}

	return;
}

void Exporter::Perform_Timed_Export(Program_Options const& program_options, std::time_t const& last_run_time){
/*
	if (program_options.Export()){
		std::cout << "Exporting... "; std::cout.flush();
	}

	//start recording the time
	//it takes to perform the export
	Export_Stats stats; stats.Start_Timer();

		//perform the export
		if (program_options.Export()){
			Perform_Export(program_options,stats);
		}else{
			Gather_Stats_Only(program_options,stats);
		}

	//export is done.
	//stop the timer
	stats.End_Timer();

	//conversion is complete (The pseudo library now matches the exported library in terms of content)
	if (program_options.Export()){
		Green_Message("Success!\n");
	}

	//after the successful conversion, output any other kind of desired results
	if (program_options.Stats()){
		Output_Additional_Logging_Information(stats);
	}
*/
	return;
}
/*
	void Exporter::Perform_Export(Program_Options const& program_options, Export_Stats & stats){

		//set the root of where the exported library will be.
		auto exported_library = boost::filesystem::current_path()
		/= constant::EXPORT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT;

		//make sure the root of the exported library is there
		//and that the path to it, doesn't have any redirection.
		Create_Path_If_It_Doesnt_Already_Exist(exported_library);
		Shortify_Path(exported_library);

		//assuming the program is being run at the root of the pseudo library,
		//this function will export the complete working version of the actual library.
		//(it will only update/create parts of the library that aren't already done)
		//(it will also remove parts of the actual library, that are no longer in the pseudo library)
		Start_The_Library_Conversion(program_options, exported_library, stats);

		return;
	}
		void Exporter::Start_The_Library_Conversion(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats){

		//perform any checks needed before conversion/update occurs

		//perform the conversion / update
		std::vector<std::string> namespace_stack;
		Convert_Directory_And_All_Sub_Directories(program_options, exported_library,stats, namespace_stack);

		return;
	}
			void Exporter::Convert_Directory_And_All_Sub_Directories(Program_Options const& program_options, boost::filesystem::path const& exported_library, Export_Stats & stats,  std::vector<std::string> & namespace_stack){

		Create_Path_If_It_Doesnt_Already_Exist(exported_library); //don't delete or boost::filesystem will throw

		//make the .cpp file and the .hpp file for the current namespace
		Make_Header_And_Source_File_For_Current_Namespace(program_options,exported_library,stats, namespace_stack);

		//recursively do this across all sub-directories
		Convert_All_The_Sub_Files(program_options,exported_library,stats,namespace_stack);

		return;
	}
				void Exporter::Make_Header_And_Source_File_For_Current_Namespace(Program_Options const& program_options,boost::filesystem::path const& exported_library, Export_Stats & stats,  std::vector<std::string> const& namespace_stack){

		std::ofstream header(exported_library.string() + "/" + Current_Folder_Name() + ".hpp");
		std::ofstream source(exported_library.string() + "/" + Current_Folder_Name() + ".cpp");

		std::ofstream header_headers_file(exported_library.string() + "/" + Current_Folder_Name() + "_hheaders.hpp");
		std::ofstream source_headers_file(exported_library.string() + "/" + Current_Folder_Name() + "_sheaders.hpp");

		//start - header
		Make_Header_File_Start(header_headers_file,header,program_options,namespace_stack);

		//start - source
		Make_Source_File_Start(source_headers_file,source,program_options,namespace_stack);

		//output the actual code (functions, classes, etc)
		Export_Library_Code(source,header,program_options,stats,namespace_stack);

		//end - header
		Make_Header_File_End(header,program_options,namespace_stack);

		//end - source
		Make_Source_File_End(source,namespace_stack);

		return;
	}

//header shell code
void Exporter::Make_Header_File_Start(std::ofstream & header_headers_file,std::ofstream & header, Program_Options const& program_options,std::vector<std::string> const& namespace_stack){

	std::ifstream header_hpps(boost::filesystem::current_path().string() + "/" + constant::HEADER_HPPS_FILE);

	//use pragma once or inclusion guards
	if (program_options.Inclusion_Guards()){
		header << "#ifndef JSTD_UNIQUE_INCLUSION_GUARD_" << include_gaurd_global << '\n';
		header << "#define JSTD_UNIQUE_INCLUSION_GUARD_" << include_gaurd_global << '\n';
		++include_gaurd_global;
	}else{
		header << "#pragma once\n";
	}
	header << "#include \"" + Current_Folder_Name() + "_hheaders.hpp\"\n";

	//output the header_hpps
	std::string temp;
	std::getline(header_hpps,temp);
	while (header_hpps){
		header_headers_file << temp <<'\n';
		std::getline(header_hpps,temp);
	}

	//dump all includes and using namespaces as well as function decelerations
	Implement_Header(header_headers_file,header,program_options,namespace_stack);
	return;
}
void Exporter::Implement_Header(std::ofstream & header_headers_file,std::ofstream & header, Program_Options const& program_options,std::vector<std::string> const& namespace_stack){

	//get all the directories of the pseudo library node
	auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());


	//output all the subdir includes
	for (auto const& dir: dirs){
		header_headers_file << "#include \"" << Current_Folder_Name() << "/" << dir << ".hpp\"\n";
	}

	for (auto it: namespace_stack){header <<  "namespace " <<  it << "{";}
	header << "namespace " << Current_Folder_Name() << "{";

	//output all the using statements
	for (auto const& dir: dirs){
		header << "using namespace " << dir << ";";
	}

	//put special marker to deal with pragma once
	if (!program_options.Inclusion_Guards()){
		if (dirs.empty()){
			header << "//unique pragma marker: " << boost::filesystem::current_path().string() << " (" << pragma_unique_maker_global << ")\n";
			++pragma_unique_maker_global;
		}
	}

	return;
}
void Exporter::Make_Header_File_End(std::ofstream & header, Program_Options const& program_options,std::vector<std::string> const& namespace_stack){

	for (size_t i = 0; i < namespace_stack.size()+1; ++i){header <<  "}";}

	//finish pragma once or inclusion guards
	if (program_options.Inclusion_Guards()){header << "\n#endif";}

	header.close();
}

//source shell  code
void Exporter::Make_Source_File_Start(std::ofstream & source_headers_file,std::ofstream & source,Program_Options const& program_options,std::vector<std::string> const& namespace_stack){

	std::ifstream source_hpps(boost::filesystem::current_path().string() + "/" + constant::SOURCE_HPPS_FILE);
	source << "#include \"" + Current_Folder_Name() + "_sheaders.hpp\"\n";


	//include the header!
	source_headers_file << "#include \"" << Current_Folder_Name() << ".hpp" << "\"\n";

	//output the source_hpps
	std::string temp;
	std::getline(source_hpps,temp);
	while (source_hpps){
		source_headers_file << temp <<'\n';
		std::getline(source_hpps,temp);
	}

	//start of namespace stack
	for (auto it: namespace_stack){source <<  "namespace " <<  it << "{";}
	source << "namespace " << Current_Folder_Name() << "{";
	return;
}
void Exporter::Make_Source_File_End(std::ofstream & source,std::vector<std::string> const& namespace_stack){
	for (size_t i = 0; i < namespace_stack.size()+1; ++i){source <<  "}";}
	source.close();
	return;
}

//both middle code
void Exporter::Export_Library_Code(std::ofstream & source, std::ofstream & header,Program_Options const& program_options, Export_Stats & stats,std::vector<std::string> const& namespace_stack){
		std::ifstream code((boost::filesystem::current_path() /= "code.hpp").string());
		std::string line;
		std::vector<std::string> function_block;

		std::getline(code,line);
		while(code){
			if(line == constant::START_OF_FUNCTION_MARKER){
				std::getline(code,line);
				while(code && line != constant::END_OF_FUNCTION_MARKER){
					function_block.push_back(line);
					std::getline(code,line);
				}
				Print_Functions(program_options,header,source,function_block,stats,namespace_stack);
				function_block.clear();
			}

			std::getline(code,line);
		}
		return;
	}













void Exporter::Print_Functions(Program_Options const& program_options,std::ofstream & header,std::ofstream & source,std::vector<std::string> const& function_block, Export_Stats & stats,std::vector<std::string> const& namespace_stack){

		//convert the function chunk into a use-able class
		Function function = Get_Function(function_block);

		//don't output the functions if it's specified to be c++11 only and we specify that we aren't using c++11!

		if (!(!program_options.CPP11() && !function.language_versions.empty())){

			//solve the regular expressions
			std::vector<std::string> function_names;
			std::vector<std::string> part;

			//add all the function synonyms
			if (!program_options.Base_Functions_Only()){
				for (auto it: function.function_name_expressions){
					part = Get_Results_Of_Regular_Expression_Solver(it);
					function_names.insert( function_names.end(), part.begin(), part.end() ); //function_names += part;
				}
			}

			//raw adds
			if (!program_options.Base_Functions_Only()){
				for (auto it: function.raw_adds){
					function_names.push_back(it);
				}
			}

			//raw deletes
			if (!program_options.Base_Functions_Only()){
				for (auto it: function.raw_deletes){
					function_names.erase(std::remove(function_names.begin(), function_names.end(), it), function_names.end());
				}
			}

			//add base function
			function_names.push_back(function.function_base);


			//get rid of un-needed whitespce
			for (auto & it: function_names){
				trim(it);
				Squeeze_Away_Spaces(it);
			}

			//get all function case conventions
			Convert_To_Needed_Function_Formats(program_options,function_names);

			//sort and remove duplicates
			Sort_And_Remove_Duplicates(function_names); //<- should warn what the repeats were

			//record function amount
			if (!function_names.empty()){
				stats.Increment_Base_Function();
				stats.Increment_Function_Synonyms(function_names.size()-1);
			}


			//OUTPUT TEMPLATE FUNCTION
			if (!function.template_statement.empty()){
				for (auto it = function_names.begin(); it != function_names.end(); ++it){

					for (auto const& t_part: function.template_statement){
						header << t_part;
					}
					if (program_options.CPP11()){
						header << "auto " << *it << "(" << function.get_paramater_list() << ")->" << function.return_type;
					}else{
						header << function.return_type << " " << *it << "(" << function.get_paramater_list() << ")";
					}

					if (*it == function.function_base){
						for (auto line: function.definition){
							header << line << '\n';
						}
					}else{
						header << "{ return " << function.function_base << "(" << function.get_passed_in_values() << ");}";
					}
				}
			}
			else{


				//OUTPUT NON-TEMPLATE FUNCTION
				for (auto & it: function_names){

					//OUTPUT NORMAL FUNCTION IN HEADER
					if (program_options.CPP11()){
						header << "auto " << it << "(" << function.get_paramater_list() << ")->" << function.return_type  << ";";
					}else{
						header << function.return_type << " " << it << "(" << function.get_paramater_list() << ");";
					}
				}

				//OUTPUT NORMAL FUNCTION IN SOURCE
				for (auto it = function_names.begin(); it != function_names.end(); ++it){

					if (program_options.CPP11()){
						source << "auto " << *it << "(" << function.get_paramater_list() << ")->" << function.return_type;
					}else{
						source << function.return_type << " " << *it << "(" << function.get_paramater_list() << ")";
					}

					if (*it == function.function_base){
						for (auto line: function.definition){
							source << line << '\n';
						}
					}else{
						source << "{ return " << function.function_base << "(" << function.get_passed_in_values() << ");}";
					}
				}
			}
		}

		return;
	}
							Function Exporter::Get_Function(std::vector<std::string> const& function_block){

		std::vector<std::string>::const_iterator it = function_block.begin();
		Function function;
		Get_Doxygen_Documentation(function,it);
		Get_Attribute_Part(function,it);
		Get_Template_Part(function,it);
		Get_Parameters_Part(function,it);
		Get_Regex_Part(function,it);
		Get_Definition_Part(function,it);
		Get_Raw_Adds_Part(function,it);
		Get_Raw_Deletes_Part(function,it);
		Get_Function_Base_Part(function,it);
		Get_CPlus_Plus_Version_Only(function,it,function_block.cend());

		return function;
	}
								void Exporter::Get_Doxygen_Documentation(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.doxygen_documentation.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Attribute_Part(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.attributes.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Template_Part(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.template_statement.push_back(*it);
			++it;
		}
		++it;

		return;
	}
								void Exporter::Get_Parameters_Part(Function & function, std::vector<std::string>::const_iterator & it){

		function.return_type = *it;
		++it;
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.parameters.push_back(std::pair<std::string,std::string>(*(it),*(it+1)));
			it+=2;
		}
		++it;

		return;
	}
								void Exporter::Get_Regex_Part(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.function_name_expressions.push_back(*it);
			++it;
		}
		++it;

		return;
	}
								void Exporter::Get_Definition_Part(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.definition.push_back(*it);
			++it;
		}
		++it;

		return;
	}
								void Exporter::Get_Raw_Adds_Part(Function & function, std::vector<std::string>::const_iterator & it){

		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.raw_adds.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Raw_Deletes_Part(Function & function, std::vector<std::string>::const_iterator & it){
		while (*it != constant::FUNCTION_PART_DELIMITER){
			function.raw_deletes.push_back(*it);
			++it;
		}
		++it;
									return;
								}
								void Exporter::Get_Function_Base_Part(Function & function, std::vector<std::string>::const_iterator & it){
									function.function_base = *it;
									++it;
									++it;
									return;
								}
								void Exporter::Get_CPlus_Plus_Version_Only(Function & function, std::vector<std::string>::const_iterator & it, std::vector<std::string>::const_iterator end){

		while (it != end){
			function.language_versions.push_back(*it);
			++it;
		}
		return;
	}
							std::vector<std::string> Exporter::Get_Results_Of_Regular_Expression_Solver(std::string & regular_expression){

	Resolve_Regular_Expression_Compacts(regular_expression);
	Function_Expression_Generator generator(regular_expression);

	return generator.Get_Generations();
}
								void Exporter::Resolve_Regular_Expression_Compacts(std::string & regular_expression){
									std::string built;
									std::string temp;

									for (auto it = regular_expression.cbegin(); it != regular_expression.cend(); ++it){

										//for possible empty sets
										if (*it == '<'){
											++it;
											while (*it != '>'){
												temp+=*it;
												++it;
											}
											built+=Resolve_Compact(temp,true);
											temp.clear();

										}

										//for stationary sets
										else if (*it == '#'){
											++it;
											while (*it != '#'){
												temp+=*it;
												++it;
											}
											built+=Resolve_Compact(temp,false);
											temp.clear();
										}

										//for all other characters
										else{
											built+=*it;
										}
									}



									regular_expression = built;
									return;
								}
									std::string Exporter::Resolve_Compact(std::string const& compact, bool const& empty){

										std::ifstream infile(constant::PATH_TO_REGEX_COMPACTS + compact);
										std::string word;
										std::vector<std::string> words;
										std::string resolved = "(";

										std::getline(infile,word);
										while(infile){
											words.push_back(word);
										std::getline(infile,word);
										}

										for (auto it = words.begin(); it != words.end(); ++it){
											resolved+=*it;

											if (words.size() >1){
												if (it != words.end()-1){
													resolved+="|";
												}
											}

										}

										if (empty){
											resolved+="|";
										}
										resolved+=")";

										return resolved;
									}
							void Exporter::Convert_To_Needed_Function_Formats(Program_Options const& program_options,std::vector<std::string>& vec){

		std::vector<std::string> all;
		for (auto const& it: vec){

			if (program_options.Cases()[0]){
				all.push_back(As_Lowercase_Underscore_Form(it));
			}

			if (program_options.Cases()[1]){
				all.push_back(As_Uppercase_Underscore_Form(it));
			}

			if (program_options.Cases()[2]){
				all.push_back(As_Lowercase_Camelcase_Form(it));
			}

			if (program_options.Cases()[3]){
				all.push_back(As_Uppercase_Camelcase_Form(it));
			}
		}
		vec = all;
		return;
	}
								std::string Exporter::As_Lowercase_Underscore_Form(std::string const& original){
		std::string str;
		for (auto const& it: original){
			if (it == ' '){
				str+="_";
			}else{
				str+=it;
			}
		}

		return str;
	}
								std::string Exporter::As_Uppercase_Underscore_Form(std::string const& original){
		std::string str;
		bool was_space = true;
		for (auto const& it: original){
			if (it == ' '){
				str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}

		return str;
	}
								std::string Exporter::As_Uppercase_Camelcase_Form(std::string const& original){
		std::string str;
		bool was_space = true;
		for (auto const& it: original){
			if (it == ' '){
				//str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}

		return str;
	}
								std::string Exporter::As_Lowercase_Camelcase_Form(std::string const& original){
		std::string str;
		bool was_space = false;
		for (auto const& it: original){
			if (it == ' '){
				//str+="_";
				was_space = true;
			}else{
				if (was_space){
					str+=toupper(it);
					was_space = false;
				}
				else{
					str+=it;
				}
			}
		}

		return str;
	}
				void Exporter::Convert_All_The_Sub_Files(Program_Options const& program_options, boost::filesystem::path exported_library, Export_Stats & stats,  std::vector<std::string> & namespace_stack){

		//get all the directories of the pseudo library node
		auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());


		for (auto const& dir: dirs){
			namespace_stack.push_back(Current_Folder_Name());
			exported_library /= Current_Folder_Name();
			Step_Into_Folder(dir);

			Convert_Directory_And_All_Sub_Directories(program_options,exported_library,stats,namespace_stack);

			namespace_stack.pop_back();
			exported_library /= "../";
			Shortify_Path(exported_library);
			Step_Out_Of_Folder();
		}

		return;
	}



void Exporter::Gather_Stats_Only(Program_Options const& program_options,Export_Stats & stats){

		//perform the conversion / update
		std::vector<std::string> namespace_stack;
		Get_Stats_Of_Directory_And_All_Sub_Directories(program_options, stats, namespace_stack);

	return;
}
void Exporter::Get_Stats_Of_Directory_And_All_Sub_Directories(Program_Options const& program_options, Export_Stats & stats,  std::vector<std::string> & namespace_stack){

		//make the .cpp file and the .hpp file for the current namespace
		Get_Stats_For_Current_Namespace(program_options,stats, namespace_stack);

		//recursively do this across all sub-directories
		Get_Stats_Of_All_The_Sub_Files(program_options,stats,namespace_stack);

	return;
}
void Exporter::Get_Stats_For_Current_Namespace(Program_Options const& program_options, Export_Stats & stats,  std::vector<std::string> const& namespace_stack){

		std::ifstream code((boost::filesystem::current_path() /= "code.hpp").string());
		std::string line;
		std::vector<std::string> function_block;

		std::getline(code,line);
		while(code){
			if(line == constant::START_OF_FUNCTION_MARKER){
				std::getline(code,line);
				while(code && line != constant::END_OF_FUNCTION_MARKER){
					function_block.push_back(line);
					std::getline(code,line);
				}
				Stat_Functions(program_options,function_block,stats,namespace_stack);
				function_block.clear();
			}

			std::getline(code,line);
		}
		return;
	}
void Exporter::Stat_Functions(Program_Options const& program_options,std::vector<std::string> const& function_block, Export_Stats & stats,std::vector<std::string> const& namespace_stack){

		//convert the function chunk into a use-able class
		Function function = Get_Function(function_block);
		std::string expression;
		Function_Expression_Generator generator;

		if (!(!program_options.CPP11() && !function.language_versions.empty())){
			mpz_class total=0;

			//add all the function synonyms
			if (!program_options.Base_Functions_Only()){
				for (auto it: function.function_name_expressions){
					expression = it;
					Resolve_Regular_Expression_Compacts(expression);
					generator.Set_New_Expression(expression);
					total+=generator.Get_Count();
				}
			}

			//raw adds
			if (!program_options.Base_Functions_Only()){
				total+= function.raw_adds.size();
			}

			//raw deletes
			if (!program_options.Base_Functions_Only()){
				total-= function.raw_deletes.size();
			}

			stats.Increment_Base_Function();
			stats.Increment_Function_Synonyms(4*(total-1)); //we assume 4, but this would be a mis-calculation for functions names that are only a word

		}

		return;
	}




void Exporter::Get_Stats_Of_All_The_Sub_Files(Program_Options const& program_options, Export_Stats & stats,  std::vector<std::string> & namespace_stack){

		//get all the directories of the pseudo library node
		auto dirs = Get_Dirs_Of_Path(boost::filesystem::current_path().string());

		for (auto const& dir: dirs){
			namespace_stack.push_back(Current_Folder_Name());
			Step_Into_Folder(dir);

			Get_Stats_Of_Directory_And_All_Sub_Directories(program_options,stats,namespace_stack);

			namespace_stack.pop_back();
			Step_Out_Of_Folder();
		}

		return;
	}





























	void Exporter::Output_Additional_Logging_Information(Export_Stats & stats){
		std::cout << "unique function signatures: " << mpz_class(stats.Number_Of_Base_Functions() + stats.Number_Of_Function_Synonyms()).get_str() << std::endl;
		std::cout << "base function signatures: " << stats.Number_Of_Base_Functions().get_str() << std::endl;
		//std::cout << "The export took " << stats.Duration() << " seconds." << std::endl;
		return;
	}
*/
