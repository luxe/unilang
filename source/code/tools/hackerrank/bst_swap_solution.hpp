#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/types/tree/tree_node_properties.hpp"

template <typename T>
T* min(T* a, T* b){
    return a->val < b->val ? a : b;
}
template <typename T>
void swap_values(std::pair<T*,T*> & nodes){
    std::swap(nodes.first->val,nodes.second->val);
}

template <typename T>
bool discrepancy_found(std::pair<T*,T*> const& window){
    return window.first->val > window.second->val;
}

//how to choose the first node when finding a broken constraint
template <typename T>
void handle_first_discrepancy(std::pair<T*,T*> & nodes, std::pair<T*,T*> const& window){
    nodes = window;
}

//how to choose the second node when finding a broken constraint
template <typename T>
void handle_second_discrepancy(std::pair<T*,T*> & nodes, std::pair<T*,T*> const& window){
    nodes.second = min(window.first,window.second);
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & nodes, std::pair<T*,T*> const& window){
    
    if (discrepancy_found(window)){
        
        //handle storing first discrepancy
        if (!nodes.first){
            handle_first_discrepancy(nodes,window);
        }
        else{
            handle_second_discrepancy(nodes,window);
        }
    }
}

template <typename T>
void fix_bst(T *root){
    
    //store only two node pointers 
    //we want to prove that this can be done without an additional third pointer
    //(as many online solutions show)
    std::pair<T*,T*> nodes {nullptr,nullptr};
    
    Tree_Traversal::perform_inorder_with_previous(root,[&](std::pair<T*,T*> window){
        store_nodes_for_swapping(nodes,window);
    });
    
    //fix the tree based on the two node pointers captured
    swap_values(nodes);
}