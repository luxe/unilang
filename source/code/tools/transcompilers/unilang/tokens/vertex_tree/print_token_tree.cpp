#include <iostream>
#include "code/transcompilers/unilang/tokens/vertex_tree/as_vertex_graph.hpp"

int main(){
    auto tree = As_Vertex_Graph::Get();
    tree.Print();
}