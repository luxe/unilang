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
       2   10 
      /  \ /  \ 
     1   3 7   12
   /      \    /
  0        4  11
     */
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    BinaryNode<int> r7(4);
    BinaryNode<int> r8(11);
    BinaryNode<int> r9(0);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    root.left->right->right = &r7;
    root.right->right->left = &r8;
    root.left->left->left = &r9;
  
  
    
    // BinaryNode<int> root(2);
    // BinaryNode<int> r1(1);
    // BinaryNode<int> r2(3);
    // BinaryNode<int> r3(11);
    // BinaryNode<int> r4(5);
    // BinaryNode<int> r5(4);
    // BinaryNode<int> r6(7);
    // BinaryNode<int> r7(6);
    // BinaryNode<int> r8(10);
    // BinaryNode<int> r9(8);
    // BinaryNode<int> r10(9);
    
    // root.left = &r1;
    // root.right = &r2;
    // root.right->right = &r3;
    // root.right->right->left = &r4;
    // root.right->right->left->left = &r5;
    // root.right->right->left->right = &r6;
    // root.right->right->left->right->left = &r7;
    // root.right->right->left->right->right = &r8;
    // root.right->right->left->right->right->left = &r9;
    // root.right->right->left->right->right->left->right = &r10;
    
    
    //setup state
    // Annotated_Bst_State state;
    // state.a = &root;
    // state.b = nullptr;
    // state.root = &root;
    // state.current_photo = 0;
    // state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    
    // Annotated_Bst_Fix::fix(state);
    
    // Tree_Traversal::morris_traversal(&root,[&](BinaryNode<int>* n){
    //     std::cout << n->val << " ";
    //     std::cout.flush();
    // });
    // std::cout << std::endl;
    // Tree_Traversal::morris_traversal(&root,[&](BinaryNode<int>* n){
    //     std::cout << n->val << " ";
    //     std::cout.flush();
    // });
    // std::cout << std::endl;
    // Tree_Traversal::morris_traversal(&root,[&](BinaryNode<int>* n){
    //     std::cout << n->val << " ";
    //     std::cout.flush();
    // });
    // std::cout << std::endl;
    
    auto x = Tree_Traversal::get_binary_node_heights(&root);
    for (auto const& it: x){
      std::cout << it.height << " " << it.node.val << std::endl;
    }
}