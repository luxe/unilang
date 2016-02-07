#include "call_graph_exporter.hpp"
#include "structure_enums.hpp"











 void Call_Graph_Exporter::Export(Structure structure, std::vector<Contributor> const& contributors, std::string const& style){

  Call_Graph_Options settings;
  std::ofstream outfile(structure.name + "." + settings.file_extension);
  outfile << Structure_As_Local_Call_Graph(structure,settings) << "\n";
}

 std::string Call_Graph_Exporter::Structure_As_Local_Call_Graph(Structure structure, Call_Graph_Options const& settings){
  std::string str;
  
  Append_With_Newline(str,"digraph " + structure.name + " {");
      Append_With_Newline(str,Overall_Graph_Options(settings));
      Append_With_Newline(str,Create_Interface_Subgraph(structure.methods.methods));
      Append_With_Newline(str,Create_Interface_Subgraph(structure.methods.methods));
      Append_With_Newline(str,Create_Implementation_Subgraph(structure.methods.methods));
      Append_With_Newline(str,Get_Connections_For_Methods(structure.methods.methods));
  Append_With_Newline(str,"}");
  
  return str;
}

 std::string Call_Graph_Exporter::Overall_Graph_Options(Call_Graph_Options const& settings){
  std::string str;
  Append_With_Newline(str,"rankdir=LR");
  return str;
}



 std::string Call_Graph_Exporter::Create_Interface_Subgraph(std::vector<Method_Item> const& methods){
  std::string str;
  Append_With_Newline(str,"subgraph cluster_interface {");
  Append_With_Newline(str,"label = \"Interface\";");
  Append_With_Newline(str,"color=blue;");
  Append_With_Newline(str,"rank=1");
  Append_With_Newline(str,Get_Public_Declarations(methods));
  Append_With_Newline(str,"}");
  return str;
}
 std::string Call_Graph_Exporter::Create_Implementation_Subgraph(std::vector<Method_Item> const& methods){
  std::string str;
  Append_With_Newline(str,"subgraph cluster_implementation {");
  Append_With_Newline(str,"label = \"Implementation\";");
  Append_With_Newline(str,"color=blue;");
  Append_With_Newline(str,"rank=2");
  Append_With_Newline(str,Get_Private_Declarations(methods));
  Append_With_Newline(str,"}");
  return str;
}



 std::string Call_Graph_Exporter::Get_Connections_For_Methods(std::vector<Method_Item> const& methods){
  std::string str;
  
    for (auto item: methods){
      for (auto it: item.body){
        if (it.name == Body_Token_Name::SELF_FUNCTION_CALL){
          str += '"' + as_string(item.function_name.value) + "\" -> \"";
          Append_With_Newline(str,as_string(it.value) + "\";");
        }
      }
    }
  
  return str;
}








//utilities
 std::string Call_Graph_Exporter::Get_All_Declarations(std::vector<Method_Item> const& methods){

  std::string str;
  for (auto it: methods){
    str += '"' + as_string(it.function_name.value) + "\";\n";
  }
  return str;
}

 std::string Call_Graph_Exporter::Get_Public_Declarations(std::vector<Method_Item> const& methods){

  std::string str;
  for (auto it: methods){
    if (it.class_access == Class_Access::PUBLIC){
      str += '"' + as_string(it.function_name.value) + "\";\n";
    }
  }
  return str;
}
 std::string Call_Graph_Exporter::Get_Protected_Declarations(std::vector<Method_Item> const& methods){

  std::string str;
  for (auto it: methods){
    if (it.class_access == Class_Access::PROTECTED){
      str += '"' + as_string(it.function_name.value) + "\";\n";
    }
  }
  return str;
}
 std::string Call_Graph_Exporter::Get_Private_Declarations(std::vector<Method_Item> const& methods){

  std::string str;
  for (auto it: methods){
    if (it.class_access == Class_Access::PRIVATE){
      str += '"' + as_string(it.function_name.value) + "\";\n";
    }
  }
  return str;
}
