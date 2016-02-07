#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "structure.hpp"
#include "contributor.hpp"
#include "call_graph_options.hpp"

class Call_Graph_Exporter{










public: static void Export(Structure structure, std::vector<Contributor> const& contributors, std::string const& style);

private: static std::string Structure_As_Local_Call_Graph(Structure structure, Call_Graph_Options const& settings);

private: static std::string Overall_Graph_Options(Call_Graph_Options const& settings);



private: static std::string Create_Interface_Subgraph(std::vector<Method_Item> const& methods);
private: static std::string Create_Implementation_Subgraph(std::vector<Method_Item> const& methods);



private: static std::string Get_Connections_For_Methods(std::vector<Method_Item> const& methods);








//utilities
private: static std::string Get_All_Declarations(std::vector<Method_Item> const& methods);

private: static std::string Get_Public_Declarations(std::vector<Method_Item> const& methods);
private: static std::string Get_Protected_Declarations(std::vector<Method_Item> const& methods);
private: static std::string Get_Private_Declarations(std::vector<Method_Item> const& methods);
};