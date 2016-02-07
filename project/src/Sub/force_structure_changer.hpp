#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "structure.hpp"
#include "struct_manipulation_settings.hpp"

class Force_Structure_Changer{









public: static void Manipulate_Code_Structure_Based_Off_Of_Options(Structure & structure, Struct_Manipulation_Settings const& options);

private: static void Manipulate_Meta_Section(Struct_Manipulation_Settings const& options, Meta_Section & meta_section);


private: static void Manipulate_Import_Section(Struct_Manipulation_Settings const& options, Import_Section & import_section);


private: static void Force_Headers_To_Be_System(Import_Section & import_section, std::vector<std::string> const& header_names);


private: static void Force_Headers_To_Have_A_Dot_H(Import_Section & import_section, std::vector<std::string> const& header_names);


};