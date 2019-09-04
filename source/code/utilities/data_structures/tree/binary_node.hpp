#pragma once

template <typename T>
struct BinaryNode {
    
    BinaryNode(T val):
    val(val) {}
        
    T val;
    struct BinaryNode *left = nullptr;
    struct BinaryNode *right = nullptr;
};