#include <iostream>
#include "code/transcompilers/unilang/tokens/as_vertex_graph.hpp"

int main(){
    auto tree = As_Vertex_Graph::Get();
    tree.Print();
}