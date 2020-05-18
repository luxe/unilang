#include "Sub/Custom_Base/composed_program_options/program_options_composer.hpp"







 Composed_Program_Options Program_Options_Composer::Compose(Program_Options const& program_options) {

  //import files
Composed_Program_Options composed;
  composed.program_name = program_options.Program_Name();
composed.move = program_options.Move();
 
  
  return composed;

}
