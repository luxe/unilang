#pragma once
#include "code/utilities/deps/external/boost_graph/lib.hpp"
#include <vector>
#include <map>

//class
class Unique_Str_Vertex_Graph{

  public:
  bool Add(std::string const& t);
  bool Connect(std::string const& x, std::string const& y);
  void Print(); //<- useful for debug
  bool Exists(std::string const& x);
  std::string As_Graphviz();
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,std::string> Get_Underlining_Graph();

  private:
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,std::string> graph;

  //holds the id descriptors and lets us enforce unique-ness
  std::map<std::string,int> vertexes;
  
  //holds all of the connections and lets us enforce unique edges
  std::vector<std::string> connections;

  //the names of all the vertices sent to graphviz for printing
  std::vector<std::string> names;

};
