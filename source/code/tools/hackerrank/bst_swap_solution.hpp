#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/types/tree/tree_node_properties.hpp"

template <typename T>
T* min(std::pair<T*,T*> const& nodes){
    return nodes.first->val < nodes.second->val ? nodes.first : nodes.second;
}
template <typename T>
void swap_values(std::pair<T*,T*> & nodes){
    std::swap(nodes.first->val,nodes.second->val);
}

template <typename T>
bool inorder_discrepancy_found(std::pair<T*,T*> const& window){
    return window.first->val > window.second->val;
}
template <typename T>
bool outorder_discrepancy_found(std::pair<T*,T*> const& window){
    return window.first->val < window.second->val;
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & nodes, std::pair<T*,T*> const& window){
    
    if (inorder_discrepancy_found(window)){
        
        //handle storing first discrepancy
        if (!nodes.first){
            nodes = window;
        }
        else{
            nodes.second = window.second;
        }
    }
}

template <typename T>
void fix_bst_with_sliding_window_and_two_ptr_storage(T *root){
    
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

template <typename T>
void fix_bst_with_2_ptrs(T *root){
    
    try {
        Tree_Traversal::perform_inorder_with_previous(Tree_Traversal::get_earliest_nullptr_inorder(root),root,[&](std::pair<T*,T*> window){
            if (inorder_discrepancy_found(window)){
                throw window.first;
            }
        });
    }
    catch(T* ptr1){
        
        try {
            Tree_Traversal::perform_outorder_with_previous(Tree_Traversal::get_earliest_nullptr_outorder(root),root,[&](std::pair<T*,T*> window){
                if (outorder_discrepancy_found(window)){
                    throw window.first;
                }
            });
        }
        catch(T* ptr2){
            std::swap(ptr1->val,ptr2->val);
        }
    }
    
    // T* ptr2 = root;
    
    // try { Tree_Traversal::bst_inorder_throw_discrepancy(root); }
    // catch (T* root){
    //     try { Tree_Traversal::bst_outorder_throw_discrepancy(ptr2); }
    //     catch (T* ptr2){
    //         std::cout << root->val << " " << ptr2->val << std::endl;
    //         std::swap(root->val,ptr2->val);
    //         return;
    //     }
        
    //     std::cout << "here" << std::endl;
    // }
}