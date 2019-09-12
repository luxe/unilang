#pragma once
#include <vector>
#include <memory>
#include "code/utilities/data_structures/tree/binary_nodes.hpp"


struct Bst_Tree_Example {
    BinaryNodes<int> tree;
    
    //if empty than the tree is already correct
    std::vector<std::pair<BinaryNode<int>*,BinaryNode<int>*>> swapped_nodes;
};