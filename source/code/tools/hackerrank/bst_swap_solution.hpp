#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/types/tree/tree_node_properties.hpp"

//printing utility
template <typename T>
std::string as_str(T* t){
    if (!t){
        return "null";
    }
    return std::to_string(t->val);
}

//algorithm specific
//how to choose the first node when finding a broken constraint
template <typename T>
T* choose_first_node(T* previous, T* t){
    
    if (Tree_Node_Properties::are_adjacent(t,previous)){
        return Tree_Node_Properties::get_parent(t,previous);
    }
    return previous;
}

//algorithm specific
//how to choose the second node when finding a broken constraint
template <typename T>
T* choose_second_node(T* previous, T* t){
    
    if (Tree_Node_Properties::are_adjacent(t,previous)){
        return Tree_Node_Properties::get_parent(t,previous);
    }
    return t;
}

//algorithm specific
//how to swap based on the two node pointers you have
template <typename T>
void swap_found_nodes(std::pair<T*,T*> & finds){
    
    //tree is already fixed
    if (!finds.first && !finds.second){
        return;
    }
    
    //only one node was stored
    //there is a problem with adjacent nodes
    //luckily we stored the parent, and can
    //rediscover which node needs swapped
    if (Tree_Node_Properties::both_children_are_invalid(finds.first)){
        std::swap(finds.first->left->val,finds.first->right->val);
        return;
    }
    
    //std::cout << as_str(finds.first) << " " << as_str(finds.second) << std::endl;
    
    if (!finds.second){
        auto child = Tree_Node_Properties::find_invalid_child(finds.first);
        std::swap(finds.first->val,child->val);
        return;
    }
    
    //non-adjacent nodes need swapped,
    //and they are stored correctly.
    auto child1 = Tree_Node_Properties::find_invalid_child(finds.first);
    auto child2 = Tree_Node_Properties::find_invalid_child(finds.second);
    
    if (child1 && child2){
        
        if (finds.first->val < finds.second->val){
            std::swap(child1->val,child2->val);
            return;
        }
        
        if (Tree_Node_Properties::is_right_child(finds.first,child1) && Tree_Node_Properties::is_right_child(finds.second,child2)){
            std::swap(finds.first->val,child2->val);
            return;
        }
        
        std::swap(finds.first->val,finds.second->val);
        return;
    }
    
    auto to_swap1 = child1 ? child1 : finds.first;
    auto to_swap2 = child2 ? child2 : finds.second;
    
    //std::cout << "actual: " << to_swap1->val << " " << to_swap2->val << std::endl;
    
    std::swap(to_swap1->val,to_swap2->val);
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & finds, T* previous, T* t){
    if (previous->val > t->val){
        
        
        //handle storing first discrepancy
        if (!finds.first){
            finds.first = choose_first_node(previous,t);
        }
        
        //handle storing non-first discrepancies
        else{
            
            if (finds.second){
                finds.first = finds.second;
            }
            
            finds.second = choose_second_node(previous,t);
        }
    }
}



template <typename T>
void fix_bst(T *root){
    
    //store only two nodes 
    std::pair<T*,T*> finds {nullptr,nullptr};
    
    Tree_Traversal::perform_inorder_with_previous(root,[&](T* previous, T* t){
        store_nodes_for_swapping(finds,previous,t);
    });
    
    //fix the tree
    swap_found_nodes(finds);
}