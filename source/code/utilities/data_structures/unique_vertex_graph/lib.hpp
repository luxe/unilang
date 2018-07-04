#pragma once
#include <boost/graph/directed_graph.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <vector>
#include <map>

//class
template <typename T>
class Unique_Vertex_Graph{

  public:
  bool Add(T const& t);
  bool Connect(T const& x, T const& y);
  void Print(); //<- useful for debug
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,T> Get_Underlining_Graph();

  private:
  boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,T> graph;
  std::map<T,int> vertexes;
};


//methods
template <typename T>
bool Unique_Vertex_Graph<T>::Add(T const& t){
  auto found = vertexes.find(t);
  if (found != vertexes.end()){
    return false;
  }
  
  auto id = boost::add_vertex(t, graph);
  vertexes.emplace(t,id);
  return true;
}

template <typename T>
bool Unique_Vertex_Graph<T>::Connect(T const& x, T const& y){
  
  Add(x);
  Add(y);
  auto x_find = vertexes.find(x);
  auto y_find = vertexes.find(y);
  
  if (x_find != vertexes.end() && y_find != vertexes.end()){
    boost::add_edge(x_find->second, y_find->second, graph);
    return true;
  }
  
  return false;
}

template <typename T>
void Unique_Vertex_Graph<T>::Print(){
  boost::write_graphviz(std::cout, graph);
}

template <typename T>
boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS,T> Unique_Vertex_Graph<T>::Get_Underlining_Graph(){
  return graph;
}
