#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"

//check if parent is really a parent of child
template <typename T>
bool is_parent_of(T* parent, T* child){
    if (parent->left){
        if (parent->left->val == child->val){
            return true;
        }
    }
    if (parent->right){
        if (parent->right->val == child->val){
            return true;
        }
    }
    return false;
}

//given a parent node,
//return the immediate child that invalidates a BST structure
template <typename T>
T* find_invalid_child(T* parent){
    if (parent->left){
        if (parent->left->val > parent->val){
            return parent->left;
        }
    }
    if (parent->right){
        if (parent->right->val < parent->val){
            return parent->right;
        }
    }
    return nullptr;
}

//algorithm specific
//how to choose the first node when finding a broken constraint
template <typename T>
T* choose_first_node(T* previous, T* t){
    
    if (is_parent_of(t,previous)){
        return t;
    }
    return previous;
}

//algorithm specific
//how to choose the second node when finding a broken constraint
template <typename T>
T* choose_second_node(T* previous, T* t){
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
    if (!finds.second){
        
        auto child = find_invalid_child(finds.first);
        std::swap(finds.first->val,child->val);
        return;
    }
    
    //non-adjacent nodes need swapped,
    //and they are stored correctly.
    std::swap(finds.first->val,finds.second->val);
}

template <typename T>
void store_nodes_for_swapping(std::pair<T*,T*> & finds, T* previous, T* t){
    if (previous->val > t->val){
        
        
        //handle storing first node
        if (!finds.first){
            finds.first = choose_first_node(previous,t);
        }
        
        //handle storing second node
        else{
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