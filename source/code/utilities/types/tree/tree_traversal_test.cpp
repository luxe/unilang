#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_fix.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_state.hpp"
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
          \
           4
     10 and 2 are swapped
     */
    BinaryNode<int> root(6);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(2);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    BinaryNode<int> r7(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    root.left->right->right = &r7;
    
    
    //setup state
    Annotated_Bst_State state;
    state.a = &root;
    state.b = nullptr;
    state.root = &root;
    state.current_photo = 0;
    state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    
    Annotated_Bst_Fix::fix(state);
}