#pragma once

template <typename T>
struct BinaryNode {
    
    BinaryNode(T val_in):
    val(val_in) {}
    
    BinaryNode()
    {}
        
    T val;
    struct BinaryNode *left = nullptr;
    struct BinaryNode *right = nullptr;
};
