#include "Sub/Custom_Base/options/program_options_composer.hpp"







 Composed_Program_Options Program_Options_Composer::Compose(Program_Options const& program_options) {

  Composed_Program_Options composed;
  composed.program_name = program_options.Program_Name();
  composed.move = program_options.Move();
composed.additional_libs = program_options.Additional_Libraries();
  
  //converts all the program_options into a composed version.
  //this way we can organize information into nested structures as desired
  
  return composed;

}
