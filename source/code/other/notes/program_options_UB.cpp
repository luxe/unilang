#include <iostream>
#include <string>
#include <boost/program_options.hpp>

int main(int const argc, char** const argv){

  using namespace boost::program_options;
  
  //create description
  options_description desc("");
  
  //add entry
  desc.add_options()
  ("foo",value<std::string>(),"desc");
  
  //create variable map
  variables_map vm;
  
  //store variables in map
  positional_options_description pod;
	store(command_line_parser(argc, argv).options(desc).positional(pod).run(), vm);
	notify(vm);
	
	//get variable out of map
	std::string foo;
	if (vm.count("foo")){
		foo = vm["foo"].as<std::string>(); //UNDEFINED BEHAVIOUR
	}
}
