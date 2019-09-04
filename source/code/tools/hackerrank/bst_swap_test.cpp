#include "code/tools/hackerrank/bst_swap_solution.hpp"
#include "code/utilities/types/tree/tree_traversal.hpp"
#include "gtest/gtest.h"
#include <algorithm>

void wrong_by_only_two_nodes(std::vector<int> nodes){
  auto sorted = nodes;
  std::sort(sorted.begin(),sorted.end());
  
  int discrepency_count = 0;
  for (size_t i = 0; i < sorted.size(); ++i){
    if (nodes[i] != sorted[i]){
      ++discrepency_count;
    }
  }
  EXPECT_EQ(discrepency_count,2);
}

void check_tree_fix(BinaryNode<int> & root){
  auto before = Tree_Traversal::inorder_traversal_as_list(&root);
  fix_bst(&root);
  auto after = Tree_Traversal::inorder_traversal_as_list(&root);
  
  EXPECT_FALSE(std::is_sorted(before.begin(),before.end()));
  wrong_by_only_two_nodes(before);
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

TEST(BST_Fix, NonAdjacent_3) {
    /*
           2
         /  \
        3    1
    3 and 1 are swapped (non-adjacent)
    */
    BinaryNode<int> root(2);
    BinaryNode<int> r1(3);
    BinaryNode<int> r2(1);
    root.left = &r1;
    root.right = &r2;
    check_tree_fix(root);
}
TEST(BST_Fix, NonAdjacent_4) {
    /*
           2
         /  \
        1    3
       /      \
      4        0
    4 and 0 are swapped (non-adjacent)
    */
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(0);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_tree_fix(root);
}
TEST(BST_Fix, NonAdjacent_5) {
    /*
          4
         /  \
        3    5
       /      \
      2        6
     /          \
    7            1
    7 and 1 are swapped (non-adjacent)
    */
    BinaryNode<int> root(4);
    BinaryNode<int> r1(3);
    BinaryNode<int> r2(5);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(1);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    root.left->left->left = &r5;
    root.right->right->right = &r6;
    check_tree_fix(root);
}
TEST(BST_Fix, NonAdjacent_6) {
    /*
          7
         /  \
        3    5
       /      \
      2        6
     /          \
    1            4
    7 and 4 are swapped (non-adjacent)
    */
    BinaryNode<int> root(7);
    BinaryNode<int> r1(3);
    BinaryNode<int> r2(5);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(1);
    BinaryNode<int> r6(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    root.left->left->left = &r5;
    root.right->right->right = &r6;
    check_tree_fix(root);
}

TEST(BST_Fix, Adjacent_1) {
    /*
          10
         /  \
        6    20
       / \
      2   5
    5 and 6 are swapped(adjacent)
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
    4 and 5 are swapped(adjacent)
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

TEST(BST_Fix, Adjacent_3) {
    /*
           5
         /  \
        10    20
       / \
      4   7
    5 and 10 are swapped(adjacent)
    */
    BinaryNode<int> root(5);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(7);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_tree_fix(root);
}