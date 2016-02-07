#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "structure.hpp"
#include "contributor.hpp"

class Plant_Uml_Exporter{








public: static void Export(Structure structure, std::vector<Contributor> const& contributors, std::string const& style);

private: static std::string Structure_As_String(Structure const& structure);


private: static std::string Get_Method_String(Method_Item const& method_item);

private: static std::string Get_Data_Member_String(Data_Member_Item const& data_member_item);


private: static std::string Class_Access_As_String(Class_Access const& class_access);

};