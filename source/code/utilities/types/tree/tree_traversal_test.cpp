#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/utilities/data_structures/tree/binary_node.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_fix.hpp"
#include "code/utilities/types/tree/bst/annotated_bst_state.hpp"
#include "code/utilities/data_structures/tree/binary_nodes.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

TEST(bst_inorder_throw_discrepancy, NonAdjacent_1) {
    
    
    
  //        2
  //      /  \
  //     3    1
  // 3 and 1 are swapped
  // BinaryNodes<int> x;
  // x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(2));
  // x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(3));
  // x.nodes.emplace_back(std::make_shared<BinaryNode<int>>(1));
  // x.nodes[0]->left = &*x.nodes[1];
  // x.nodes[0]->right = &*x.nodes[2];
  
  
        /*
         6 
        /  \ 
       10   2 
      /  \ /  \ 
     1   3 7   12
   /      \    /
  0        4  11
     */
    // BinaryNode<int> root(6);
    // BinaryNode<int> r1(10);
    // BinaryNode<int> r2(2);
    // BinaryNode<int> r3(1);
    // BinaryNode<int> r4(3);
    // BinaryNode<int> r5(7);
    // BinaryNode<int> r6(12);
    // BinaryNode<int> r7(4);
    // BinaryNode<int> r8(11);
    // BinaryNode<int> r9(0);
    // root.left = &r1;
    // root.right = &r2;
    // root.left->left = &r3;
    // root.left->right = &r4;
    // root.right->left = &r5;
    // root.right->right = &r6;
    // root.left->right->right = &r7;
    // root.right->right->left = &r8;
    // root.left->left->left = &r9;
    
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(11);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(4);
    BinaryNode<int> r6(7);
    BinaryNode<int> r7(6);
    BinaryNode<int> r8(10);
    BinaryNode<int> r9(8);
    BinaryNode<int> r10(9);
    
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    root.right->right->left = &r4;
    root.right->right->left->left = &r5;
    root.right->right->left->right = &r6;
    root.right->right->left->right->left = &r7;
    root.right->right->left->right->right = &r8;
    root.right->right->left->right->right->left = &r9;
    root.right->right->left->right->right->left->right = &r10;
    
    
    
    
    // BinaryNode<int> root(12);
    // BinaryNode<int> r1(1);
    // BinaryNode<int> r2(23);
    // BinaryNode<int> r3(11);
    // BinaryNode<int> r4(13);
    // BinaryNode<int> r5(2);
    // BinaryNode<int> r6(22);
    // BinaryNode<int> r7(10);
    // BinaryNode<int> r8(14);
    // BinaryNode<int> r9(3);
    // BinaryNode<int> r10(21);
    // BinaryNode<int> r11(9);
    // BinaryNode<int> r12(15);
    // BinaryNode<int> r13(4);
    // BinaryNode<int> r14(20);
    // BinaryNode<int> r15(8);
    // BinaryNode<int> r16(16);
    // BinaryNode<int> r17(5);
    // BinaryNode<int> r18(19);
    // BinaryNode<int> r19(7);
    // BinaryNode<int> r20(17);
    // BinaryNode<int> r21(6);
    // BinaryNode<int> r22(18);
    
    // BinaryNode<int> r23(24);
    // BinaryNode<int> r24(25);
    // BinaryNode<int> r25(26);
    // BinaryNode<int> r26(27);
    // BinaryNode<int> r27(31);
    // BinaryNode<int> r28(28);
    // BinaryNode<int> r29(30);
    // BinaryNode<int> r30(29);
    // root.left = &r1;
    // root.right = &r2;
    // root.left->right = &r3;
    // root.right->left = &r4;
    // root.left->right->left = &r5;
    // root.right->left->right = &r6;
    // root.left->right->left->right = &r7;
    // root.right->left->right->left = &r8;
    // root.left->right->left->right->left = &r9;
    // root.right->left->right->left->right = &r10;
    // root.left->right->left->right->left->right = &r11;
    // root.right->left->right->left->right->left = &r12;
    // root.left->right->left->right->left->right->left = &r13;
    // root.right->left->right->left->right->left->right = &r14;
    // root.left->right->left->right->left->right->left->right = &r15;
    // root.right->left->right->left->right->left->right->left = &r16;
    // root.left->right->left->right->left->right->left->right->left = &r17;
    // root.right->left->right->left->right->left->right->left->right = &r18;
    // root.left->right->left->right->left->right->left->right->left->right = &r19;
    // root.right->left->right->left->right->left->right->left->right->left = &r20;
    // root.left->right->left->right->left->right->left->right->left->right->left = &r21;
    // root.right->left->right->left->right->left->right->left->right->left->right = &r22;
    
    // root.right->right = &r23;
    // root.right->right->right = &r24;
    // root.right->right->right->right = &r25;
    // root.right->right->right->right->right = &r26;
    // root.right->right->right->right->right->right = &r27;
    // root.right->right->right->right->right->right->left = &r28;
    // root.right->right->right->right->right->right->left->right = &r29;
    // root.right->right->right->right->right->right->left->right->left = &r30;
    
    //setup state
    Annotated_Bst_State state;
    state.a = &root;
    state.b = nullptr;
    state.root = &root;
    state.current_photo = 0;
    state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
    state.val_heights = Tree_Traversal::get_binary_node_levels(&root);
    state.original_connections = Tree_Traversal::get_all_directed_relationships(&root);
    
    
    
    //setup state
  // auto real_root = *x.nodes[0];
  //   Annotated_Bst_State state;
  //   state.a = &real_root;
  //   state.b = nullptr;
  //   state.root = &real_root;
  //   state.current_photo = 0;
  //   state.all_nodes = Tree_Traversal::inorder_traversal_as_node_list(state.root);
  //   state.val_heights = Tree_Traversal::get_binary_node_levels(&real_root);
  //   state.original_connections = Tree_Traversal::get_all_directed_relationships(&real_root);
    
    Annotated_Bst_Fix::fix(state);
    
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
}





