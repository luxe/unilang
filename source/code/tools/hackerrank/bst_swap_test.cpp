#include "code/utilities/types/tree/tree_traversal.hpp"
#include "code/tools/hackerrank/bst_swap_solution_sliding_window_two_ptrs.hpp"
#include "code/tools/hackerrank/bst_swap_solution_in_out.hpp"
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

void check_algorithm_fixes_tree(BinaryNode<int> & root){
  auto before = Tree_Traversal::inorder_traversal_as_list(&root);
  Bst_Swap_Solution_Sliding_Window_Two_Ptrs::fix_bst(&root);
  auto after = Tree_Traversal::inorder_traversal_as_list(&root);
  
  EXPECT_FALSE(std::is_sorted(before.begin(),before.end()));
  wrong_by_only_two_nodes(before);
  EXPECT_TRUE(std::is_sorted(after.begin(),after.end()));
}

void check_every_swap_combination(BinaryNode<int> & root){
    auto ordered = Tree_Traversal::inorder_traversal_as_node_list(&root);
    for (size_t i = 0; i < ordered.size(); ++i){
      for (size_t j = 0; j < ordered.size(); ++j){
        if (ordered[i]->val != ordered[j]->val){
          std::swap(ordered[i]->val,ordered[j]->val);
          //std::cout << "swapped " << ordered[i]->val << " " << ordered[j]->val << std::endl;
          check_algorithm_fixes_tree(root);
        }
      }
    }
}

TEST(BST_Fix, NonAdjacent_1) {
        
     //     6 
     //    /  \ 
     //   10   2 
     //  /  \ /  \ 
     // 1   3 7  12 
     // 10 and 2 are swapped
     
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
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, NonAdjacent_2) {
    
    //       10
    //      /  \
    //     5    8
    //    / \
    //   2   20
    // 20 and 8 are swapped
    
    BinaryNode<int> root(10);
    BinaryNode<int> r1(5);
    BinaryNode<int> r2(8);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(20);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, NonAdjacent_3) {
    
    //        2
    //      /  \
    //     3    1
    // 3 and 1 are swapped
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(3);
    BinaryNode<int> r2(1);
    root.left = &r1;
    root.right = &r2;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, NonAdjacent_4) {
    
    //        2
    //      /  \
    //     1    3
    //    /      \
    //   4        0
    // 4 and 0 are swapped
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(0);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, NonAdjacent_5) {
    
    //       4
    //      /  \
    //     3    5
    //    /      \
    //   2        6
    //  /          \
    // 7            1
    // 7 and 1 are swapped
    
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
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, NonAdjacent_6) {
    
    //       7
    //      /  \
    //     3    5
    //    /      \
    //   2        6
    //  /          \
    // 1            4
    // 7 and 4 are swapped
    
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
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, NonAdjacent_7) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /  \ 
     // 12   3 7  1 
     // 12 and 1 are swapped
     
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(12);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(1);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, Adjacent_1) {
    
    //       10
    //      /  \
    //     6    20
    //    / \
    //   2   5
    // 5 and 6 are swapped
    
    BinaryNode<int> root(10);
    BinaryNode<int> r1(6);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(5);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, Adjacent_2) {
    
    //       10
    //      /  \
    //     4    20
    //    / \
    //   5   7
    // 4 and 5 are swapped
    
    BinaryNode<int> root(10);
    BinaryNode<int> r1(4);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(7);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root);
}

TEST(BST_Fix, Adjacent_3) {
    
    //        5
    //      /  \
    //     10    20
    //    / \
    //   4   7
    // 5 and 10 are swapped
    
    BinaryNode<int> root(5);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(20);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(7);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_4) {
    
    //        1
    //      /  \
    //     2    3
    // 2 and 1 are swapped
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    root.left = &r1;
    root.right = &r2;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_5) {
    
    //        1
    //      /  \
    //     2    3
    //    /
    //   0
    // 2 and 1 are swapped
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_6) {
    
    //        1
    //      /  \
    //     2    3
    //           \
    //            4
    // 2 and 1 are swapped
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_7) {
    
    //        1
    //      /  \
    //     2    3
    //   /       \
    //  0         4
    // 2 and 1 are swapped
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    BinaryNode<int> r4(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_8) {
    
 //           20
 //         /
 //        19
 //      /
 //     18
 //    /
 //   5
 //  / \
 // 6   7
   
 //    6 and 5 are swapped
    
    BinaryNode<int> root(20);
    BinaryNode<int> r1(19);
    BinaryNode<int> r2(18);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(7);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->right = &r5;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_9) {
    
 //           20
 //         /
 //        19
 //      /
 //     18
 //    /
 //   7
 //  / \
 // 5   6
   
 //    7 and 6 are swapped
    
    BinaryNode<int> root(20);
    BinaryNode<int> r1(19);
    BinaryNode<int> r2(18);
    BinaryNode<int> r3(7);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(6);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->right = &r5;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_10) {
    
    //        3
    //      /  \
    //     1    2
    // 3 and 2 are swapped
    
    BinaryNode<int> root(3);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(2);
    root.left = &r1;
    root.right = &r2;
    check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_11) {
  
  // 2
  //  \
  //   1
  //   1 and 2 are swapped
  
  BinaryNode<int> root(2);
  BinaryNode<int> r1(1);
  root.right = &r1;
  check_algorithm_fixes_tree(root);
}
TEST(BST_Fix, Adjacent_12) {
  
  //  1
  // /
  // 2
  //   2 and 1 are swapped
  
  BinaryNode<int> root(1);
  BinaryNode<int> r1(2);
  root.left = &r1;
  check_algorithm_fixes_tree(root);
}


TEST(BST_Fix, Every_Swap_1) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /  \ 
     // 1   3 7  12 
     
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
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
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_2) {
    
        //    2
        //  /  \
        // 1    3
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    root.left = &r1;
    root.right = &r2;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_3) {
    
     //       2
     //     /  \
     //    1    3
     //  /       \
     // 0         4
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(0);
    BinaryNode<int> r4(4);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_4) {
    
     // 1-2-3-4-5-6-7-8-9-10
    
    BinaryNode<int> root(10);
    BinaryNode<int> r1(9);
    BinaryNode<int> r2(8);
    BinaryNode<int> r3(7);
    BinaryNode<int> r4(6);
    BinaryNode<int> r5(5);
    BinaryNode<int> r6(4);
    BinaryNode<int> r7(3);
    BinaryNode<int> r8(2);
    BinaryNode<int> r9(1);
    root.left = &r1;
    root.left->left = &r2;
    root.left->left->left = &r3;
    root.left->left->left->left = &r4;
    root.left->left->left->left->left = &r5;
    root.left->left->left->left->left->left = &r6;
    root.left->left->left->left->left->left->left = &r7;
    root.left->left->left->left->left->left->left->left = &r8;
    root.left->left->left->left->left->left->left->left->left = &r9;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_5) {
    
     // 1-2-3-4-5-6-7-8-9-10
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(4);
    BinaryNode<int> r4(5);
    BinaryNode<int> r5(6);
    BinaryNode<int> r6(7);
    BinaryNode<int> r7(8);
    BinaryNode<int> r8(9);
    BinaryNode<int> r9(10);
    root.right = &r1;
    root.right->right = &r2;
    root.right->right->right = &r3;
    root.right->right->right->right = &r4;
    root.right->right->right->right->right = &r5;
    root.right->right->right->right->right->right = &r6;
    root.right->right->right->right->right->right->right = &r7;
    root.right->right->right->right->right->right->right->right = &r8;
    root.right->right->right->right->right->right->right->right->right = &r9;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_6) {
    
    //  2
    // /
    // 1
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    root.left = &r1;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_7) {
    
     // 1
     // \
     //  2
    
    BinaryNode<int> root(1);
    BinaryNode<int> r1(2);
    root.right = &r1;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_8) {
    
        //    2
        //  /  \
        // 1    3
        //       \
        //        5
        //       / \
        //      4   6
    
    BinaryNode<int> root(2);
    BinaryNode<int> r1(1);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(4);
    BinaryNode<int> r5(6);
    root.left = &r1;
    root.right = &r2;
    root.right->right = &r3;
    root.right->right->left = &r4;
    root.right->right->right = &r5;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_9) {
    
      //       5
      //      / \
      //     4   6
      //    /
      //   2
      //  / \
      // 1   3
    
    BinaryNode<int> root(5);
    BinaryNode<int> r1(4);
    BinaryNode<int> r2(6);
    BinaryNode<int> r3(2);
    BinaryNode<int> r4(1);
    BinaryNode<int> r5(3);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->left->left = &r4;
    root.left->left->right = &r5;
    check_every_swap_combination(root);
}

TEST(BST_Fix, Every_Swap_10) {
  
  
  // 13
  // /
  // 11
  // \
  //  12
  //  /
  //  9
  //  \
  //   10
  
    BinaryNode<int> root(13);
    BinaryNode<int> r1(11);
    BinaryNode<int> r2(12);
    BinaryNode<int> r3(9);
    BinaryNode<int> r4(10);
    root.left = &r1;
    root.left->right = &r2;
    root.left->right->left = &r3;
    root.left->right->left->right = &r4;
    check_every_swap_combination(root);
}

TEST(BST_Fix, Every_Swap_11) {
  
  
   // 1
   //  \
   //   6
   //  /
   // 3
   //  \
   //   5
   //   /
   //  4
    
  
    BinaryNode<int> root(1);
    BinaryNode<int> r1(6);
    BinaryNode<int> r2(3);
    BinaryNode<int> r3(5);
    BinaryNode<int> r4(4);
    root.right = &r1;
    root.right->left = &r2;
    root.right->left->right = &r3;
    root.right->left->right->left = &r4;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_12) {
        
     //     6 
     //    /  \ 
     //   2    10 
     //  /  \ /   \ 
     // 1   3 7     12
     //      \  \   /
     //      4  8  11
     
    BinaryNode<int> root(6);
    BinaryNode<int> r1(2);
    BinaryNode<int> r2(10);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    BinaryNode<int> r7(4);
    BinaryNode<int> r8(8);
    BinaryNode<int> r9(11);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    root.left->right->right = &r7;
    root.right->left->right = &r8;
    root.right->right->left = &r9;
    check_every_swap_combination(root);
}
TEST(BST_Fix, Every_Swap_13) {
    
   //        10
   //       /  \
   //      9    11
   //    /       \
   //   8         12
   //  /           \
   // 0             20
   //  \            /
   //   1          19
   //     \       / 
   //       2   18
   //        \  /
   //        3  17
    
    
    
    BinaryNode<int> root(10);
    BinaryNode<int> r1(9);
    BinaryNode<int> r2(11);
    BinaryNode<int> r3(8);
    BinaryNode<int> r4(12);
    BinaryNode<int> r5(0);
    BinaryNode<int> r6(20);
    BinaryNode<int> r7(1);
    BinaryNode<int> r8(19);
    BinaryNode<int> r9(2);
    BinaryNode<int> r10(18);
    BinaryNode<int> r11(3);
    BinaryNode<int> r12(17);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.right->right = &r4;
    root.left->left->left = &r5;
    root.right->right->right = &r6;
    root.left->left->left->right = &r7;
    root.right->right->right->left = &r8;
    root.left->left->left->right->right = &r9;
    root.right->right->right->left->left = &r10;
    root.left->left->left->right->right->right = &r11;
    root.right->right->right->left->left->left = &r12;
    check_every_swap_combination(root);
}









