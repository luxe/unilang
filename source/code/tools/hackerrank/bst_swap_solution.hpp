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

template <typename T>
bool are_adjacent(T* node1, T* node2){
    return is_parent_of(node1,node2) || is_parent_of(node2,node1);
}

template <typename T>
T* get_parent(T* node1, T* node2){
    if (is_parent_of(node1,node2)){
        return node1;
    }
    if (is_parent_of(node2,node1)){
        return node2;
    }
    return nullptr;
}


template <typename T>
bool left_child_breaks_constraint(T* parent)
{
    if (parent->left){
        if (parent->left->val > parent->val){
            return true;
        }
    }
    return false;
}

template <typename T>
bool right_child_breaks_constraint(T* parent)
{
    if (parent->right){
        if (parent->right->val < parent->val){
            return true;
        }
    }
    return false;
}

//given a parent node,
//return the immediate child that invalidates a BST structure
template <typename T>
T* find_invalid_child(T* parent){
    
    if (left_child_breaks_constraint(parent)){
        return parent->left;
    }
    if (right_child_breaks_constraint(parent)){
        return parent->right;
    }
    return nullptr;
}

template <typename T>
bool both_children_are_invalid(T* parent){
    return left_child_breaks_constraint(parent) && right_child_breaks_constraint(parent);
}

//algorithm specific
//how to choose the first node when finding a broken constraint
template <typename T>
T* choose_first_node(T* previous, T* t){
    
    if (are_adjacent(t,previous)){
        return get_parent(t,previous);
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
    
    std::cout << finds.first->val << " " << finds.second->val << std::endl;
    
    //only one node was stored
    //there is a problem with adjacent nodes
    //luckily we stored the parent, and can
    //rediscover which node needs swapped
    if (both_children_are_invalid(finds.first)){
        std::cout << "this" << std::endl;
        std::swap(finds.first->left->val,finds.first->right->val);
        return;
    }
    if (!finds.second){
        auto child = find_invalid_child(finds.first);
        std::swap(finds.first->val,child->val);
        return;
    }
    
    //non-adjacent nodes need swapped,
    //and they are stored correctly.
    auto child1 = find_invalid_child(finds.first);
    auto child2 = find_invalid_child(finds.second);
    
    auto to_swap1 = child1 ? child1 : finds.first;
    auto to_swap2 = child2 ? child2 : finds.second;
    
    std::cout << "actual: " << to_swap1->val << " " << to_swap2->val << std::endl;
    
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
            
            finds.second = choose_first_node(previous,t);
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