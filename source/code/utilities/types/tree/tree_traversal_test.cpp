#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>

TEST(bst_inorder_throw_discrepancy, NonAdjacent_1) {
        /*
         6 
        /  \ 
       10   2 
      /  \ /  \ 
     1   3 7  12 
     10 and 2 are swapped
     */
    BinaryNode<int> root(6);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(2);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    
    
    BinaryNode<int>* ptr2 = &root;
    
    
    try { Tree_Traversal::bst_inorder_throw_discrepancy(&root); }
    catch (BinaryNode<int>* root){
            std::cout << root->val << std::endl;
        try { Tree_Traversal::bst_outorder_throw_discrepancy(ptr2); }
        catch (BinaryNode<int>* ptr2){
            std::cout << ptr2->val << std::endl;
        }
    }
}