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
    if (Tree_Node_Properties::both_children_break_bst_constraint(finds.first)){
        std::swap(finds.first->left->val,finds.first->right->val);
        return;
    }
    
    //std::cout << as_str(finds.first) << " " << as_str(finds.second) << std::endl;
    
    //non-adjacent nodes need swapped,
    //and they are stored correctly.
    auto child1 = Tree_Node_Properties::find_invalid_child(finds.first);
    auto child2 = Tree_Node_Properties::find_invalid_child(finds.second);
    
    
    if (child1 && child2){
        
        if (finds.first->val < finds.second->val){
            std::swap(child1->val,child2->val);
            return;
        }
    }
        
    if (child1){
        if (finds.first->val < child1->val && child1->val > finds.second->val){
            std::swap(child1->val,finds.second->val);
            return;
        }
    }
    if (child2){
        if (finds.second->val > child2->val && child2->val < finds.first->val){
            std::swap(finds.first->val,child2->val);
            return;
        }
    }
    
    std::swap(finds.first->val,finds.second->val);
    return;
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & finds, T* previous, T* t){
    if (previous->val > t->val){
        
        
        //handle storing first discrepancy
        if (!finds.first){
            finds.first = choose_first_node(previous,t);
            
            
            
            //in the case we dont actually find another
            //store this in the second
            if (finds.first->val == previous->val){
                finds.second = t;
            }
            else{
                finds.second = previous;
            }
            
            
            
        }
        else{
            finds.second = choose_second_node(previous,t);
        }
    }
}



template <typename T>
void fix_bst(T *root){
    
    //store only two node pointers 
    //we want to prove that this can be done without an additional third pointer
    //(as many online solutions show)
    std::pair<T*,T*> finds {nullptr,nullptr};
    
    Tree_Traversal::perform_inorder_with_previous(root,[&](T* previous, T* t){
        store_nodes_for_swapping(finds,previous,t);
    });
    
    //fix the tree based on the two node pointers captured
    swap_found_nodes(finds);
}