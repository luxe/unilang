#include "code/tools/hackerrank/bst_swap_solution.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "gtest/gtest.h"
#include <algorithm>

void check_tree_fix(BinaryNode<int> & root){
  auto before = Tree_Traversal::inorder_traversal_as_list(&root);
  fix_bst(&root);
  auto after = Tree_Traversal::inorder_traversal_as_list(&root);
  
  EXPECT_FALSE(std::is_sorted(before.begin(),before.end()));
  EXPECT_TRUE(std::is_sorted(after.begin(),after.end()));
  
}

TEST(BST_Fix, NonAdjacent_1) {
            /*
             6 
            /  \ 
           10   2 
          /  \ /  \ 
         1   3 7  12 
         10 and 2 are swapped (non-adjacent)
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
        check_tree_fix(root);
}

TEST(BST_Fix, NonAdjacent_2) {
        /*
              10
             /  \
            5    8
           / \
          2   20
        20 and 8 are swapped (non-adjacent)
        */
        BinaryNode<int> root(10);
        BinaryNode<int> r1(5);
        BinaryNode<int> r2(8);
        BinaryNode<int> r3(2);
        BinaryNode<int> r4(20);
        root.left = &r1;
        root.right = &r2;
        root.left->left = &r3;
        root.left->right = &r4;
        check_tree_fix(root);
}

TEST(BST_Fix, Adjacent_1) {
        /*
              10
             /  \
            6    20
           / \
          2   5
        5 and 6 are swapped(non-adjacent)
        */
        BinaryNode<int> root(10);
        BinaryNode<int> r1(6);
        BinaryNode<int> r2(20);
        BinaryNode<int> r3(2);
        BinaryNode<int> r4(5);
        root.left = &r1;
        root.right = &r2;
        root.left->left = &r3;
        root.left->right = &r4;
        check_tree_fix(root);
}

TEST(BST_Fix, Adjacent_2) {
        /*
              10
             /  \
            4    20
           / \
          5   7
        4 and 5 are swapped(non-adjacent)
        */
        BinaryNode<int> root(10);
        BinaryNode<int> r1(4);
        BinaryNode<int> r2(20);
        BinaryNode<int> r3(5);
        BinaryNode<int> r4(7);
        root.left = &r1;
        root.right = &r2;
        root.left->left = &r3;
        root.left->right = &r4;
        check_tree_fix(root);
}