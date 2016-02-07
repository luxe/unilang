#include "plant_uml_exporter.hpp"









 void Plant_Uml_Exporter::Export(Structure structure, std::vector<Contributor> const& contributors, std::string const& style){
  std::ofstream outfile("class_uml.plant-uml");
  outfile << "@startuml\n";
  outfile << Structure_As_String(structure) << "\n";
  outfile << "@enduml\n";
}

 std::string Plant_Uml_Exporter::Structure_As_String(Structure const& structure){
  std::string s;
  
  s+= "class " + structure.name + " {\n";
  
  for (auto it: structure.methods.methods){
    s+= Get_Method_String(it) + "\n";
  }
  
  for (auto it: structure.data_members.data_members){
    s+= Get_Data_Member_String(it) + "\n";
  }
  
  s+= "}";
  
  return s;
}


 std::string Plant_Uml_Exporter::Get_Method_String(Method_Item const& method_item){
  std::string s;
  s+= Class_Access_As_String(method_item.class_access);
  s+= as_string(method_item.function_name.value);
  s+= "()";
  
  return s;
}

 std::string Plant_Uml_Exporter::Get_Data_Member_String(Data_Member_Item const& data_member_item){
  std::string s;
  s+= Class_Access_As_String(data_member_item.class_access);
  s+= as_string(data_member_item.name.value);
  s+= " : ";
  s+= as_string(data_member_item.type.value);
  
  return s;
}


 std::string Plant_Uml_Exporter::Class_Access_As_String(Class_Access const& class_access){
  switch (class_access){
    case Class_Access::PUBLIC: return "+";
    case Class_Access::PROTECTED: return "#";
    case Class_Access::PRIVATE: return "-";
   }
   
   return "+";
}

