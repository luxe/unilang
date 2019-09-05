#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/types/tree/tree_node_properties.hpp"

//algorithm specific
//how to choose the first node when finding a broken constraint
template <typename T>
void handle_first_discrepancy(std::pair<T*,T*> & finds, std::pair<T*,T*> const& window){
    
    finds = window;
    if (Tree_Node_Properties::are_adjacent(window.first,window.second)){
        finds = Tree_Node_Properties::as_parent_child(window);
    }
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
void decide_swap(std::pair<T*,T*> & finds){
    
    if (Tree_Node_Properties::both_children_break_bst_constraint(finds.first)){
        finds.second = finds.first->left;
        finds.first = finds.first->right;
        return;
    }
    
    auto child1 = Tree_Node_Properties::find_invalid_child(finds.first);
    auto child2 = Tree_Node_Properties::find_invalid_child(finds.second);
        
    if (child1){
        if (child1->val > finds.first->val && child1->val > finds.second->val){
            finds.first = child1;
        }
    }
    if (child2){
        if (child2->val < finds.second->val && child2->val < finds.first->val){
            finds.second = child2;
        }
    }
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & finds, std::pair<T*,T*> const& window){
    if (window.first->val > window.second->val){
        
        
        //handle storing first discrepancy
        if (!finds.first){
            handle_first_discrepancy(finds,window);
            
            
            
            // //in the case we dont actually find another
            // //store this in the second
            // if (finds.first->val == window.first->val){
            //     finds.second = window.second;
            // }
            // else{
            //     finds.second = window.first;
            // }
            
            
            
        }
        else{
            finds.second = choose_second_node(window.first,window.second);
        }
    }
}



template <typename T>
void fix_bst(T *root){
    
    //store only two node pointers 
    //we want to prove that this can be done without an additional third pointer
    //(as many online solutions show)
    std::pair<T*,T*> finds {nullptr,nullptr};
    
    Tree_Traversal::perform_inorder_with_previous(root,[&](std::pair<T*,T*> window){
        store_nodes_for_swapping(finds,window);
    });
    
    //fix the tree based on the two node pointers captured
    decide_swap(finds);
    std::swap(finds.first->val,finds.second->val);
}