#pragma once
#include <boost/graph/directed_graph.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <vector>
#include <map>

//class
class Unique_Str_Vertex_Graph{

  public:
  bool Add(std::string const& t);
  bool Connect(std::string const& x, std::string const& y);
  void Print(); //<- useful for debug
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,std::string> Get_Underlining_Graph();

  private:
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,std::string> graph;

  //holds the id descriptors and lets us enforce unique-ness
  std::map<std::string,int> vertexes;

  //the names of all the vertices sent to graphviz for printing
  std::vector<std::string> names;

};


//methods
bool Unique_Str_Vertex_Graph::Add(std::string const& t){
  
  //only add if it doesn't already exist
  auto found = vertexes.find(t);
  if (found != vertexes.end()){
    return false;
  }
  
  //add and store it so we can check for its existence later
  auto id = boost::add_vertex(t, graph);
  names.emplace_back(t);
  vertexes.emplace(t,id);
  return true;
}

bool Unique_Str_Vertex_Graph::Connect(std::string const& x, std::string const& y){
  
  Add(x);
  Add(y);
  auto x_find = vertexes.find(x);
  auto y_find = vertexes.find(y);
  
  //only connect if its not yourself
  if (x_find != vertexes.end() && y_find != vertexes.end()){
    boost::add_edge(x_find->second, y_find->second, graph);
    return true;
  }
  
  return false;
}

void Unique_Str_Vertex_Graph::Print(){
  boost::write_graphviz(std::cout, graph,boost::make_label_writer(&names[0]));
}

boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,std::string> Unique_Str_Vertex_Graph::Get_Underlining_Graph(){
  return graph;
}
